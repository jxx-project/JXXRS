//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "OS/API/Client.h"
#include "OS/API/Error.h"
#include "OS/API/Model/VersionResponse.h"
#include "OS/API/Model/VersionsResponse.h"
#include "OS/API/Model/ErrorResponse.h"
#include <JXXRS/Response.h>
#include <JXXRS/MediaType.h>
#include <JXXRS/WebTarget.h>

namespace OS { namespace API {

Client::Client(std::shared_ptr<JXXRS::Client> client) : client(client)
{
}

std::shared_ptr<Model::Version> Client::getVersion(const std::string& uri) const
{
	auto target = client->target(uri);
	auto response = target->path("/").request()->buildGet()->invoke();
	switch (response->getStatus()) {
	case 200:
		return response->getEntity<Model::VersionResponse>().version;
	case 300:
		throw Error(response->getStatus());
	default:
		auto mediaType = response->getMediaType();
		if (mediaType && (*mediaType == JXXRS::MediaType::APPLICATION_JSON)) {
			if (auto error = response->getEntity<Model::ErrorResponse>().error) {
				throw Error(move(error));
			}
		}
		throw Error(response->getStatus());
	}
}

std::shared_ptr<JXXON::List<Model::Version>> Client::getVersions(const std::string& uri) const
{
	auto target = client->target(uri);
	auto response = target->path("/").request()->buildGet()->invoke();
	switch (response->getStatus()) {
	case 200:
		throw Error(response->getStatus());
	case 300:
		return response->getEntity<Model::VersionsResponse>().versions;
	default:
		auto mediaType = response->getMediaType();
		if (mediaType && (*mediaType == JXXRS::MediaType::APPLICATION_JSON)) {
			if (auto error = response->getEntity<Model::ErrorResponse>().error) {
				throw Error(move(error));
			}
		}
		throw Error(response->getStatus());
	}
}

std::pair<std::shared_ptr<Model::Version>, std::shared_ptr<JXXON::List<Model::Version>>> Client::get(const std::string& uri) const
{
	auto target = client->target(uri);
	auto response = target->path("/").request()->buildGet()->invoke();
	switch (response->getStatus()) {
	case 200:
		return std::pair<std::shared_ptr<Model::Version>, std::shared_ptr<JXXON::List<Model::Version>>>(
			response->getEntity<Model::VersionResponse>().version, nullptr);
	case 300:
		return std::pair<std::shared_ptr<Model::Version>, std::shared_ptr<JXXON::List<Model::Version>>>(
			nullptr, response->getEntity<Model::VersionsResponse>().versions);
	default:
		auto mediaType = response->getMediaType();
		if (mediaType && (*mediaType == JXXRS::MediaType::APPLICATION_JSON)) {
			if (auto error = response->getEntity<Model::ErrorResponse>().error) {
				throw Error(move(error));
			}
		}
		throw Error(response->getStatus());
	}
}

}} // namespace OS::API
