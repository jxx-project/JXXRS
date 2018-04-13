//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXRS_PocoImpl_PoolingConnectionFactory_INCLUDED
#define JXXRS_PocoImpl_PoolingConnectionFactory_INCLUDED

#include "JXXRS/ConnectionFactory.h"
#include "JXXRS/PocoImpl/Configuration.h"
#include "JXXRS/PocoImpl/HTTPClientSessionFactory.h"
#include "JXXRS/PocoImpl/Session.h"
#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPClientSession.h>
#include <unordered_map>
#include <mutex>

namespace JXXRS { namespace PocoImpl {

class PoolingConnectionFactory : public JXXRS::ConnectionFactory
{
public:
	PoolingConnectionFactory(size_t maxConnections, bool keepAlive);
	virtual ~PoolingConnectionFactory();

	virtual std::unique_ptr<JXXRS::Connection> get(
		const JXXRS::Configuration& configuration,
		const std::string& scheme,
		const std::string& host,
		std::uint16_t port) override;

protected:
	PoolingConnectionFactory(size_t maxConnections, bool keepAlive, std::unique_ptr<HTTPClientSessionFactory> httpClientSessionFactory);

private:
	struct SessionKey {
		struct Hash {
			size_t operator()(const SessionKey& key) const;
		};

		SessionKey(
			const JXXRS::Configuration& configuration,
			const std::string& scheme,
			const std::string& host,
			std::uint16_t port);
		bool operator==(const SessionKey& other) const;
		const JXXRS::Configuration* configuration;
		const std::string scheme;
		const std::string host;
		const std::uint16_t port;
	};

	std::shared_ptr<Session> getLastReleased(const SessionKey& key) const;
	bool purgeFirstReleased();

	std::unordered_multimap<SessionKey, std::shared_ptr<Session>, SessionKey::Hash> sessions;
	std::mutex lock;
	const size_t maxSessions;
	const bool keepAlive;
	std::unique_ptr<HTTPClientSessionFactory> httpClientSessionFactory;
};

}} // namespace JXXRS::PocoImpl

#endif // JXXRS_PocoImpl_PoolingConnectionFactory_INCLUDED
