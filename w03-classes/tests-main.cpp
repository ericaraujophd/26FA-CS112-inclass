#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Pair.h"

TEST_CASE("Pair initialization", "[pair],[initialization]"){
    Pair p;
    REQUIRE(p.getFirst() == 0);
    REQUIRE(p.getSecond() == 0);
    
    SECTION("Initialize Pair with values"){
        Pair q(1,2);
        REQUIRE(q.getFirst() == 1);
        REQUIRE(q.getSecond() == 2);
    }

    SECTION("Testing the setters"){
        Pair q(6,7);
        REQUIRE(q.getFirst() == 6);
        REQUIRE(q.getSecond() == 7);
        q.setFirst(3);
        q.setSecond(4);
        REQUIRE(q.getFirst() == 3);
        REQUIRE(q.getSecond() == 7);
    }

}
