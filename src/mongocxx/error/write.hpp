// Copyright 2014 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License./**

#pragma once

#include <mongocxx/config/prelude.hpp>

#include <bsoncxx/stdx/string_view.hpp>

#include <mongocxx/stdx.hpp>

#include <cstdint>
#include <string>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN
namespace error {

class write {
   public:
    write(std::int32_t code, std::string message);

    std::int32_t code();
    stdx::string_view message();

   private:
    std::int32_t _code;
    std::string _message;
};

}  // namespace error
MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx

#include <mongocxx/config/postlude.hpp>
