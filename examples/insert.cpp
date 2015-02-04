#include <mongo/bson/builder.hpp>
#include <mongo/bson/types.hpp>
#include <mongo/driver/base/client.hpp>

using mongo::driver::base::client;
using mongo::bson::builder::document;
using namespace mongo::bson::builder::helpers;
using date = mongo::bson::types::b_date;

int main(int argc, char** argv) {
    client conn{};
    
    auto db = conn["test"];
        
    auto restaurant_doc = document{};
    restaurant_doc  
        << "address" << open_doc
          << "street"   << "2 Avenue"
          << "zipcode"  <<  "10075"
          << "building" << "1480"
          << "coord"    << open_array
            << -73.9557413 << 40.7720266
          << close_array
        << close_doc
        << "borough"  << "Manhattan"
        << "cuisine"  << "Italian"
        << "grades"   << open_array 
          << open_doc 
            << "date" << date{12323}
            << "grade" << "A"
            << "score" << 11
          << close_doc
          << open_doc
            << "date" << date{121212}
            << "grade" << "B"
            << "score"   << 17
          << close_doc
        << close_array
        << "name" << "Vella"
        << "restaurant_id" << "41704620";        

    auto res = db["restaurants"].insert_one(restaurant_doc.view());
    std::cout <<  res->inserted_id() << std::endl;
}
