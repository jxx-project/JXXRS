//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_PocoImpl_Session_INCLUDED
#define JXXRS_PocoImpl_Session_INCLUDED

#include "JXXRS/PocoImpl/HTTPClientSessionFactory.h"
#include <Poco/Net/Context.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/URI.h>
#include <memory>
#include <chrono>

namespace JXXRS { namespace PocoImpl {

class Connection;

class Session
{
public:
	Session(
		const std::string& scheme,
		const std::string& host,
		std::uint16_t port,
		bool keepAlive,
		const Poco::Net::Context::Ptr sslContext,
		const Poco::Net::HTTPClientSession::ProxyConfig& proxyConfig,
		const HTTPClientSessionFactory& httpClientSessionFactory);
	Session(const Session& other) = delete;
	Session(Session&& other) = delete;
	Session& operator=(const Session& other) = delete;
	Session& operator=(Session&& other) = delete;
	~Session();

	void acquire();
	void release();
	bool inUse() const;
	bool releasedAfter(const Session& other) const;
	Poco::Net::HTTPClientSession& getHTTPClientSession() {
		return *httpClientSession;
	}

private:
	std::unique_ptr<Poco::Net::HTTPClientSession> httpClientSession;
	bool acquired;
	std::chrono::time_point<std::chrono::high_resolution_clock> releasedAt;
	bool keepAlive;
};

}} // namespace JXXRS::PocoImpl

#endif // JXXRS_PocoImpl_Session_INCLUDED
