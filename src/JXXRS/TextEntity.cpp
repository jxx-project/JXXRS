//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#include "JXXRS/TextEntity.hpp"

namespace JXXRS {

TextEntity::TextEntity(std::string&& text, const std::string& mediaType) :
		text(std::move(text)), mediaType(mediaType)
{
}

TextEntity::~TextEntity()
{
}
  
const std::string& TextEntity::getMediaType() const
{
	return mediaType;
}

void TextEntity::writeStream(std::ostream& out) const
{
	out << text;
}

} // namespace JXXRS
