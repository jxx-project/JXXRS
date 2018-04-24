//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXRS/Entity.h"
#include "JXXRS/JsonEntity.h"
#include "JXXRS/StreamEntity.h"
#include "JXXRS/TextEntity.h"

namespace JXXRS {

Entity::Entity()
{
}

Entity::~Entity()
{
}

std::unique_ptr<Entity> Entity::json(const JXXON::Serializable& entity)
{
	return std::unique_ptr<Entity>(new JsonEntity(entity.toJson(), MediaType::APPLICATION_JSON));
}

std::unique_ptr<Entity> Entity::text(std::string&& entity)
{
	return std::unique_ptr<Entity>(new TextEntity(std::move(entity), MediaType::TEXT_PLAIN));
}

std::unique_ptr<Entity> Entity::stream(std::unique_ptr<std::istream> in)
{
	return std::unique_ptr<Entity>(new StreamEntity(std::move(in), MediaType::APPLICATION_OCTET_STREAM));
}

std::ostream& operator<<(std::ostream& out, const Entity& entity)
{
	entity.writeStream(out);
	return out;
}

} // namespace JXXRS
