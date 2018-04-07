//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/PocoImpl/PoolingConnectionFactory.h"
#include "JXXRS/PocoImpl/Connection.h"
#include <functional>

namespace JXXRS { namespace PocoImpl {

PoolingConnectionFactory::PoolingConnectionFactory(std::size_t maxSessions, bool keepAlive) : maxSessions(maxSessions), keepAlive(keepAlive)
{
}

PoolingConnectionFactory::~PoolingConnectionFactory()
{
}

std::unique_ptr<JXXRS::Connection> PoolingConnectionFactory::get(
	const JXXRS::Configuration& configuration, const std::string& scheme, const std::string& host, std::uint16_t port)
{
	SessionKey key(configuration, scheme, host, port);
	std::lock_guard<std::mutex> guard(lock);
	if (auto lastReleased = getLastReleased(key)) {
		return std::unique_ptr<Connection>(new Connection(lastReleased));
	}
	while (sessions.size() >= maxSessions) {
		if (!purgeFirstReleased()) {
			break;
		}
	}
	auto config = dynamic_cast<const Configuration&>(configuration);
	return std::unique_ptr<Connection>(
		new Connection(
			sessions.emplace(
				key, std::shared_ptr<Session>(
					new Session(
						scheme,
						host,
						port,
						keepAlive,
						config.getSSLContext(),
						config.getProxyConfig())))->second));
}

std::size_t PoolingConnectionFactory::SessionKey::Hash::operator()(const SessionKey& key) const
{
	return std::hash<const JXXRS::Configuration*>()(key.configuration) ^ std::hash<std::string>()(key.scheme) ^ std::hash<std::string>()(key.host) ^ std::hash<int>()(key.port);
}

bool PoolingConnectionFactory::SessionKey::operator==(const SessionKey& other) const
{
	return configuration == other.configuration && scheme == other.scheme && host == other.host && port == other.port;
}

PoolingConnectionFactory::SessionKey::SessionKey(
	const JXXRS::Configuration& configuration, const std::string& scheme, const std::string& host, std::uint16_t port) :
		configuration(&configuration), scheme(scheme), host(host), port(port)
{
}

std::shared_ptr<Session> PoolingConnectionFactory::getLastReleased(const SessionKey& key) const
{
	auto available = sessions.equal_range(key);
	if (available.first != available.second) {
		std::shared_ptr<Session> lastReleased;
		for (auto i = available.first; i != available.second; ++i) {
			auto session = i->second;
			if (!session->inUse()) {
				if (!lastReleased || (session->releasedAfter(*lastReleased))) {
					lastReleased = session;
				}
			}
		}
		return lastReleased;
	}
	return nullptr;
}

bool PoolingConnectionFactory::purgeFirstReleased()
{
	auto firstReleased = sessions.end();
	for (auto i = sessions.begin(); i != sessions.end(); ++i) {
		auto session = i->second;
		if (!session->inUse()) {
			if (firstReleased == sessions.end() || (firstReleased->second->releasedAfter(*session))) {
				firstReleased = i;
			}
		}
	}
	if (firstReleased != sessions.end()) {
		sessions.erase(firstReleased);
		return true;
	} else {
		return false;
	}
}

}} // namespace JXXRS::PocoImpl
