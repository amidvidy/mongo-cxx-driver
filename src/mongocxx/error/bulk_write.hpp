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

#include <mongocxx/config/prelude.hpp>

#include <cstddef>
#include <cstdint>

#include <mongocxx/error/write.hpp>
#include <mongocxx/model/write.hpp>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN
namespace error {

class bulk_write : public write {
   public:
    bulk_write(
        std::int32_t code,
        std::string message,
        std::size_t index,
        model::write write
    );

    std::size_t index();
    const model::write& write();

   private:
    std::size_t _index;
    model::write _write;
};

}  // namespace error
MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx

#include <mongocxx/config/postlude.hpp>
