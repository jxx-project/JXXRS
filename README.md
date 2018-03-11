# JXXON - A C++ REST client library

Build JSON REST clients the [JAX-RS](https://en.wikipedia.org/wiki/Java_API_for_RESTful_Web_Services) way.

## Overview

JXXRS provides a subset of the JAX-RS client specification and an inplementation based on [Poco](https://pocoproject.org) and [JXXON](https://github.com/jxx-project/JXXON).

## How to use

TBD

### Examples

TBD

## Dependencies

 * Poco >= 1.6.0
 * JXXON

## How to build

Building the JXXON library requires **CMake** >= 3.0.0.

Building a static library is as of now tested with g++ on Linux x86_64 only. In the long run it's *supposed* to be portable to any standard conformant C++11 environment also supported by Poco.

Inside the project root directory run

```
make clean
./configure
make
make install
```

to build the JXXON JsonCpp implementation, or

```
./configure
make
make install
```

Use the environment variable `Poco_DIR`, if you want to use a Poco installation in a non-default location, e.g.

```
Poco_DIR=/path-to-poco ./configure
``` 

## License

Free Software, licensed under the [Boost Software License](https://spdx.org/licenses/BSL-1.0).

## Why is it named "JXXON"?

Phonetical overlay of "CXX", the make utility macro for C++, and "JAX-RS".
