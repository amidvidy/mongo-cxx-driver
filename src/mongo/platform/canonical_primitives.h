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

#include <limits>

#include "mongo/platform/cstdint.h"

namespace mongo {

// hack to deal with our disuse of stdint types...
namespace {
    template<std::size_t sz, bool is_signed, bool is_integer>
    struct canonicalize {};

#define CANONICAL_PRIMITIVE(TYPE) \
    template<> struct canonicalize<sizeof(TYPE), \
                                   std::numeric_limits<TYPE>::is_signed, \
                                   std::numeric_limits<TYPE>::is_integer \
                      > { typedef TYPE type; };
    
    CANONICAL_PRIMITIVE(int64_t);
    CANONICAL_PRIMITIVE(int32_t);
    CANONICAL_PRIMITIVE(int16_t);
    CANONICAL_PRIMITIVE(int8_t);
    CANONICAL_PRIMITIVE(uint64_t);
    CANONICAL_PRIMITIVE(uint32_t);
    CANONICAL_PRIMITIVE(uint16_t);
    CANONICAL_PRIMITIVE(uint8_t);
    CANONICAL_PRIMITIVE(double);
    CANONICAL_PRIMITIVE(float);

#undef CANONICAL_PRIMITIVE

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
