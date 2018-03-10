//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_TextEntity_INCLUDED
#define JXXRS_TextEntity_INCLUDED

#include "JXXRS/Entity.hpp"
#include "JXXON/Serializable.hpp"
#include <ostream>
#include <string>

namespace JXXRS {

struct TextEntity : public Entity
{
	TextEntity();
	TextEntity(const TextEntity& other) = delete;
	TextEntity(TextEntity&& other) = delete;
	TextEntity& operator=(const TextEntity& other) = delete;
	TextEntity& operator=(TextEntity&& other) = delete;
	virtual ~TextEntity();
	
	virtual const std::string& getMediaType() const override;

protected:
	
	virtual void writeStream(std::ostream& out) const override;
	
private:
	
	TextEntity(std::string&& text, const std::string& mediaType);

	std::string text;
	const std::string& mediaType;

	friend struct Entity;
};

} // namespace JXXRS

#endif // JXXRS_TextEntity_INCLUDED
