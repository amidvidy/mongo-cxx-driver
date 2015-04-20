// Copyright 2015 MongoDB Inc.
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
// limitations under the License.

#include <mongocxx/error/write.hpp>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN
namespace error {

write::write(std::int32_t code, std::string message)
    : _code{std::move(code)}
    , _message{std::move(message)}
{}

std::int32_t write::code() {
    return _code;
}

stdx::string_view write::message() {
    return _message;
}

}  // namespace error
MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx
