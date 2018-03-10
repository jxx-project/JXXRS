//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/PocoImpl/PoolingConnectionFactory.hpp"
#include "JXXRS/PocoImpl/Connection.hpp"

namespace JXXRS {
namespace PocoImpl {

PoolingConnectionFactory::PoolingConnectionFactory(
	Poco::Net::Context::Ptr sslContext,
	Poco::Net::HTTPClientSession::ProxyConfig& proxyConfig,
	std::size_t maxSessions,
	bool keepAlive) :
		sslContext(sslContext), proxyConfig(proxyConfig), maxSessions(maxSessions), keepAlive(keepAlive)
{
}

PoolingConnectionFactory::~PoolingConnectionFactory()
{
}

std::unique_ptr<JXXRS::Connection> PoolingConnectionFactory::get(
	const std::string& scheme, const std::string& host, std::uint16_t port)
{
	SessionKey key(scheme, host, port);
	std::lock_guard<std::mutex> guard(lock);
	if (auto lastReleased = getLastReleased(key)) {
		return std::unique_ptr<Connection>(new Connection(lastReleased));
	}
	while (sessions.size() >= maxSessions) {
		if (!purgeFirstReleased()) {
			break;
		}
	}
	return std::unique_ptr<Connection>(
		new Connection(
			sessions.emplace(
				key, std::shared_ptr<Session>(
					new Session(
						scheme,
						host,
						port,
						keepAlive,
						sslContext,
						proxyConfig)))->second));
}

std::size_t PoolingConnectionFactory::SessionKey::Hash::operator()(const SessionKey& key) const
{
	return std::hash<std::string>()(key.scheme) ^ std::hash<std::string>()(key.host) ^ std::hash<int>()(key.port);
}

bool PoolingConnectionFactory::SessionKey::operator==(const SessionKey& other) const
{
	return scheme == other.scheme && host == other.host && port == other.port;
}

PoolingConnectionFactory::SessionKey::SessionKey(
	const std::string& scheme, const std::string& host, std::uint16_t port) :
		scheme(scheme), host(host), port(port)
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

} // namespace PocoImpl
} // namespace JXXRS
