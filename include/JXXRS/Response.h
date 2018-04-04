//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:		BSL-1.0
//


#ifndef JXXRS_Response_INCLUDED
#define JXXRS_Response_INCLUDED

#include <JXXON/Serializable.h>
#include <memory>
#include <string>

namespace JXXRS {
namespace Accessor {

template<typename T, typename Enable = void>
class GetEntity;

} // namespace Accessor

class Connection;

class Response
{
public:
	virtual ~Response()
	{
	}

	template<typename T>
	T getEntity() const
	{
		return Accessor::GetEntity<T>(*this)();
	}

	virtual int getStatus() const = 0;
	virtual std::unique_ptr<std::string> getHeaderString(const std::string& name) const = 0;
	virtual std::unique_ptr<std::string> getMediaType() const = 0;
	virtual std::istream& getStream() const = 0;

protected:
	virtual JXXON::Json getJson() const = 0;
};

namespace Accessor {

template<typename T>
class GetEntity<T, typename std::enable_if<std::is_base_of<JXXON::Serializable, T>::value>::type>
{
public:
	GetEntity(const Response& response) : response(response)
	{
	}

	T operator()() const
	{
		return T(response.getJson());
	}

private:
	const Response& response;
};

template<typename T>
class GetEntity<T, typename std::enable_if<!std::is_base_of<JXXON::Serializable, T>::value>::type>
{
public:
	GetEntity(const Response& response);
	T operator()() const;

private:
	const Response& response;
};

} // namespace Accessor
} // namespace JXXRS

#endif // JXXRS_Response_INCLUDED
