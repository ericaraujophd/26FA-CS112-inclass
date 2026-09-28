#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PyList.h"

TEST_CASE("PyList", "[pylist]"){
    PyList p; // default constructor
    REQUIRE(p.getCapacity() == 0);
    REQUIRE(p.getSize() == 0);
    
    p.append(5);
    p.append(9);
    REQUIRE(p.getCapacity() == 2);
    REQUIRE(p.getSize() == 2);
    
    // Prof. Araújo realized nothing is removing items from the list... how dumb
    
}
