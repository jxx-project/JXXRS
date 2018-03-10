//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_JsonEntity_INCLUDED
#define JXXRS_JsonEntity_INCLUDED

#include "JXXRS/Entity.hpp"
#include "JXXON/Serializable.hpp"
#include <ostream>
#include <string>

namespace JXXRS {

struct JsonEntity : public Entity
{
	
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

	friend struct Entity;
};

} // namespace JXXRS

#endif // JXXRS_JsonEntity_INCLUDED
