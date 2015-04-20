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

#include <mongocxx/error/bulk_write.hpp>

#include <utility>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN
namespace error {

bulk_write::bulk_write(std::int32_t code,
                       std::string message,
                       std::size_t index,
                       model::write write_model)
    // ns qualify write to disambiguate
    : error::write(std::move(code), std::move(message))
    , _index{std::move(index)}
    , _write{std::move(write_model)}
{}

std::size_t bulk_write::index() {
    return _index;
}

const model::write& bulk_write::write() {
    return _write;
}

}  // namespace error
MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx
