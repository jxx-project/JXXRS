//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_StreamEntity_INCLUDED
#define JXXRS_StreamEntity_INCLUDED

#include "JXXRS/Entity.hpp"
#include "JXXON/Serializable.hpp"
#include <istream>
#include <ostream>
#include <string>

namespace JXXRS {

struct StreamEntity : public Entity
{
	
	StreamEntity();
	StreamEntity(const StreamEntity& other) = delete;
	StreamEntity(StreamEntity&& other) = delete;
	StreamEntity& operator=(const StreamEntity& other) = delete;
	StreamEntity& operator=(StreamEntity&& other) = delete;
	virtual ~StreamEntity();
	
	virtual const std::string& getMediaType() const override;

protected:
	
	virtual void writeStream(std::ostream& out) const override;
	
private:
	
	StreamEntity(std::istream&& in, const std::string& mediaType);

	std::istream&& in;
	const std::string& mediaType;

	friend struct Entity;
};

} // namespace JXXRS

#endif // JXXRS_StreamEntity_INCLUDED
