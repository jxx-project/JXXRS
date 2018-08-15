//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXRS_Entity_INCLUDED
#define JXXRS_Entity_INCLUDED

#include "JXXRS/MediaType.h"
#include <JXXON/Serializable.h>
#include <istream>
#include <memory>
#include <ostream>
#include <string>

namespace JXXRS {

class Entity
{
public:
	Entity();
	virtual ~Entity();

	static std::unique_ptr<Entity> json(const JXXON::Serializable& entity);
	static std::unique_ptr<Entity> text(std::string&& entity);
	static std::unique_ptr<Entity> stream(std::unique_ptr<std::istream> in);
	virtual const std::string& getMediaType() const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Entity& entity);

protected:
	virtual void writeStream(std::ostream& out) const = 0;
};

} // namespace JXXRS

#endif // JXXRS_Entity_INCLUDED
