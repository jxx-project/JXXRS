//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/JsonEntity.h"

namespace JXXRS {

JsonEntity::JsonEntity(JXXON::Json&& json, const std::string& mediaType) :
		entity(std::move(json)), mediaType(mediaType)
{
}

JsonEntity::~JsonEntity()
{
}

const std::string& JsonEntity::getMediaType() const
{
	return MediaType::APPLICATION_JSON;
}

void JsonEntity::writeStream(std::ostream& out) const
{
	out << entity;
}

} // namespace JXXRS
