//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXRS/StreamEntity.h"

namespace JXXRS {

StreamEntity::StreamEntity(std::istream&& in, const std::string& mediaType) :
		in(std::move(in)), mediaType(mediaType)
{
}

StreamEntity::~StreamEntity()
{
}

const std::string& StreamEntity::getMediaType() const {
	return mediaType;
}

void StreamEntity::writeStream(std::ostream& out) const
{
	while (in.good()) {
		char buf[1024];
		in.readsome(buf, sizeof(buf));
		out.write(buf, in.gcount());
	}
}

} // namespace JXXRS
