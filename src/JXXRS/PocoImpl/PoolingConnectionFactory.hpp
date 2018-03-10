//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_PocoImpl_PoolingConnectionFactory_INCLUDED
#define JXXRS_PocoImpl_PoolingConnectionFactory_INCLUDED

#include "JXXRS/ConnectionFactory.hpp"
#include "JXXRS/Connection.hpp"
#include "JXXRS/PocoImpl/Session.hpp"
#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPClientSession.h>
#include <unordered_map>
#include <mutex>

namespace JXXRS {
namespace PocoImpl {

struct PoolingConnectionFactory : public JXXRS::ConnectionFactory
{
	PoolingConnectionFactory(
		Poco::Net::Context::Ptr sslContext,
		Poco::Net::HTTPClientSession::ProxyConfig& proxyConfig,
		size_t maxConnections = 20,
		bool keepAlive = true);
	virtual ~PoolingConnectionFactory();
	
	virtual std::unique_ptr<JXXRS::Connection> get(
		const std::string& scheme,
		const std::string& host,
		std::uint16_t port) override;
	
private:

	struct SessionKey {
          
		struct Hash {
			size_t operator()(const SessionKey& key) const;
		};
          
		SessionKey(const std::string& scheme, const std::string& host, std::uint16_t port);
		bool operator==(const SessionKey& other) const;
		std::string scheme;
		std::string host;
		std::uint16_t port;
          
	};

	std::shared_ptr<Session> getLastReleased(const SessionKey& key) const;
	bool purgeFirstReleased();

	std::unordered_multimap<SessionKey, std::shared_ptr<Session>, SessionKey::Hash> sessions;
	std::mutex lock;
	const size_t maxSessions;
	const bool keepAlive;
	Poco::Net::Context::Ptr sslContext;
	Poco::Net::HTTPClientSession::ProxyConfig proxyConfig;
};

} // namespace PocoImpl
} // namespace JXXRS

#endif // JXXRS_PocoImpl_PoolingConnectionFactory_INCLUDED
