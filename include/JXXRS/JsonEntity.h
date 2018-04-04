//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_JsonEntity_INCLUDED
#define JXXRS_JsonEntity_INCLUDED

#include "JXXRS/Entity.h"
#include <JXXON/Serializable.h>
#include <ostream>
#include <string>

namespace JXXRS {

class JsonEntity : public Entity
{
public:
	JsonEntity();
	JsonEntity(const JsonEntity& other) = delete;
	JsonEntity(JsonEntity&& other) = delete;
	JsonEntity& operator=(const JsonEntity& other) = delete;
	JsonEntity& operator=(JsonEntity&& other) = delete;
	virtual ~JsonEntity();

	virtual const std::string& getMediaType() const override;

protected:
	virtual void writeStream(std::ostream& out) const override;

private:
	JsonEntity(JXXON::Json&& json, const std::string& mediaType);

	JXXON::Json entity;
	const std::string& mediaType;

	friend class Entity;
};

} // namespace JXXRS

#endif // JXXRS_JsonEntity_INCLUDED
