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
// limitations under the License.

#pragma once

#include <mongocxx/config/prelude.hpp>

#include <bsoncxx/stdx/optional.hpp>

#include <mongocxx/error/write.hpp>
#include <mongocxx/error/write_concern.hpp>
#include <mongocxx/exception/operation.hpp>
#include <mongocxx/stdx.hpp>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN
namespace exception {

class MONGOCXX_API write : public operation {
 public:
    write(bsoncxx::document::value raw_server_error);

    const stdx::optional<error::write>& write_error();
    const stdx::optional<error::write_concern>& write_concern_error();
 private:
    stdx::optional<error::write> _write_error;
    stdx::optional<error::write_concern> _write_concern_error;
};

}  // namespace exception
MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx

#include <mongocxx/config/postlude.hpp>
