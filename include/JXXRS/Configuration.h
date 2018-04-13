//
// Copyright (C) 2018 Dr. Michael Steffens
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef JXXRS_Configuration_INCLUDED
#define JXXRS_Configuration_INCLUDED

namespace JXXRS {

class Configuration
{
public:
	class Object
	{
	public:
		virtual ~Object ()
		{
		}
	};

	virtual ~Configuration()
	{
	}
};

} // namespace JXXRS

#endif // JXXRS_Configuration_INCLUDED
