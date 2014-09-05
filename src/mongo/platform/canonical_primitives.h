/*    Copyright 2014 MongoDB Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

#include <boost/static_assert.hpp>
#include <limits>

#include "mongo/platform/cstdint.h"

namespace mongo {

// hack to deal with our disuse of stdint types...
namespace {
    template<std::size_t sz, bool is_signed, bool is_integer>
    struct canonicalize {};
    
    template<> struct canonicalize<8, true,  true>  { typedef int64_t  type; };
    template<> struct canonicalize<4, true,  true>  { typedef int32_t  type; };
    template<> struct canonicalize<2, true,  true>  { typedef int16_t  type; };
    template<> struct canonicalize<1, true,  true>  { typedef int8_t   type; };
    template<> struct canonicalize<8, false, true>  { typedef uint64_t type; };
    template<> struct canonicalize<4, false, true>  { typedef uint32_t type; };
    template<> struct canonicalize<2, false, true>  { typedef uint16_t type; };
    template<> struct canonicalize<1, false, true>  { typedef uint8_t  type; };
    template<> struct canonicalize<4, true,  false> { typedef float    type; };
    template<> struct canonicalize<8, true,  false> { typedef double   type; };
}

template<typename T>
struct canonical {
    typedef typename canonicalize<sizeof(T),
                                  std::numeric_limits<T>::is_signed,
                                  std::numeric_limits<T>::is_integer
                     >::type
    type;
};

}
