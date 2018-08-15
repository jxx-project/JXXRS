//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXRS/StreamEntity.h"

namespace JXXRS {

StreamEntity::StreamEntity(std::unique_ptr<std::istream> in, const std::string& mediaType) : in(std::move(in)), mediaType(mediaType)
{
}

StreamEntity::~StreamEntity()
{
}

const std::string& StreamEntity::getMediaType() const
{
	return mediaType;
}

void StreamEntity::writeStream(std::ostream& out) const
{
	out << in->rdbuf();
}

} // namespace JXXRS
