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


#include <mongocxx/exception/bulk_write.hpp>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN
namespace exception {

bulk_write::bulk_write(bsoncxx::document::value raw_server_error,
                       std::vector<model::write> processed_requests,
                       std::vector<model::write> unprocessed_requests)
    : operation(std::move(raw_server_error))
    , _processed_requests(std::move(processed_requests))
    , _unprocessed_requests(std::move(unprocessed_requests)) {

        // TODO
}

const std::vector<model::write>& bulk_write::processed_requests() {
    return _processed_requests;
}

const std::vector<model::write>& bulk_write::unprocessed_requests() {
    return _unprocessed_requests;
}

const stdx::optional<error::write_concern>& bulk_write::write_concern_error() {
    return _write_concern_error;
}

const std::vector<error::bulk_write>& bulk_write::write_errors() {
    return _write_errors;
}

}  // namespace exception
MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx
