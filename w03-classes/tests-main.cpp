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
        REQUIRE(q.getSecond() == 4);
    }

}

TEST_CASE("Operator Overload", "[add, sub]"){
    Pair p1(4,5);
    Pair p2(-3, 7);
    cout << p1;
    cout << p2;
    // cout << p1 + p2 << endl;

    SECTION("Add Pairs"){
        Pair p1(0,0);
        Pair p2(1,-2);
        REQUIRE(p1.getFirst() == 0);
        REQUIRE(p1.getSecond() == 0);
        REQUIRE(p2.getFirst() == 1);
        REQUIRE(p2.getSecond() == -2);
        
        p1.add(p2);
        REQUIRE(p1.getFirst() == 1);
        REQUIRE(p1.getSecond() == -2);
        REQUIRE(p2.getFirst() == 1);
        REQUIRE(p2.getSecond() == -2);
        
        p1.add(p2);
        REQUIRE(p1.getFirst() == 2);
        REQUIRE(p1.getSecond() == -4);
        REQUIRE(p2.getFirst() == 1);
        REQUIRE(p2.getSecond() == -2);
        
        p2.add(p1);
        REQUIRE(p1.getFirst() == 2);
        REQUIRE(p1.getSecond() == -4);
        REQUIRE(p2.getFirst() == 3);
        REQUIRE(p2.getSecond() == -6);
    }

    SECTION("Operator ="){
        Pair p;
        Pair p1(6,9);
        p = p1;

        REQUIRE(p.getFirst() == 6);
        REQUIRE(p.getSecond() == 9);
    }
}
