//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "JXXRS/Response.h"

namespace JXXRS {
namespace Accessor {

template<typename T>
GetEntity<T, typename std::enable_if<!std::is_base_of<JXXON::Serializable, T>::value>::type>::GetEntity(
	const Response& response) : response(response)
{
}

template<typename T>
T GetEntity<T, typename std::enable_if<!std::is_base_of<JXXON::Serializable, T>::value>::type>::operator()() const
{
	T result;
	response.getStream() >> result;
}

template GetEntity<std::string>::GetEntity(const Response& response);
template std::string GetEntity<std::string>::operator()() const;

template<>
std::istream& GetEntity<std::istream&>::operator()() const
{
	return response.getStream();
}

template GetEntity<std::istream&>::GetEntity(const Response& response);
template std::istream& GetEntity<std::istream&>::operator()() const;

} // namespace Accessor
} // namespace JXXRS
