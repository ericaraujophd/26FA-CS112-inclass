#define CATCH_CONFIG_MAIN
#include "List.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("default constructor", "[list]") {
    List l;
    REQUIRE(l.getSize() == 0);
    REQUIRE(l.isEmpty());
    REQUIRE_THROWS_AS(l.getFirst(), underflow_error);
    REQUIRE_THROWS_AS(l.getLast(), underflow_error);
}

TEST_CASE("append", "[list]") {
    List l;
    SECTION("one item") {
        l.append(5);
        REQUIRE(l.getSize() == 1);
        REQUIRE_FALSE(l.isEmpty());
        REQUIRE(l.getFirst() == 5);
        REQUIRE(l.getLast() == 5);
    }

    SECTION("several items") {
        l.append(5);
        l.append(9);
        l.append(12);
        REQUIRE(l.getSize() == 3);
        REQUIRE(l.getFirst() == 5);
        REQUIRE(l.getLast() == 12);
    }
}

TEST_CASE("prepend", "[list]") {
    List l;
    SECTION("into an empty list") {
        l.prepend(7);
        REQUIRE(l.getSize() == 1);
        REQUIRE(l.getFirst() == 7);
        REQUIRE(l.getLast() == 7);
    }

    SECTION("mixed with append") {
        l.append(2);
        l.prepend(1);
        l.append(3);
        l.prepend(0);
        REQUIRE(l.getSize() == 4);
        REQUIRE(l.getFirst() == 0);
        REQUIRE(l.getLast() == 3);
    }
}

TEST_CASE("indexing", "[list]") {
    List l;
    l.append(3);  // 0
    l.append(4);  // 1
    l.append(5);  // 2
    l.append(15); // 3

    REQUIRE(l[0] == 3);
    REQUIRE(l.getIndex(2) == 5);
    REQUIRE(l[3] == 15);

    l[1] = 40;
    REQUIRE(l[1] == 40);

    REQUIRE_THROWS_AS(l[4], out_of_range);
    REQUIRE_THROWS_AS(l.getIndex(100), out_of_range);
}

TEST_CASE("removeFirst", "[list]") {
    List l;
    REQUIRE_THROWS_AS(l.removeFirst(), underflow_error);

    l.append(1);
    l.append(2);
    l.append(3);

    REQUIRE(l.removeFirst() == 1);
    REQUIRE(l.getSize() == 2);
    REQUIRE(l.getFirst() == 2);

    REQUIRE(l.removeFirst() == 2);
    REQUIRE(l.removeFirst() == 3);
    REQUIRE(l.isEmpty());
    REQUIRE_THROWS_AS(l.getLast(), underflow_error);

    // the list should still work after being emptied
    l.append(10);
    REQUIRE(l.getFirst() == 10);
    REQUIRE(l.getLast() == 10);
}

TEST_CASE("copy constructor", "[list]") {
    List l;
    l.append(1);
    l.append(2);
    l.append(3);

    List l2(l);
    // REQUIRE(l2.getSize() == 3);
    // REQUIRE(l2[0] == 1);
    // REQUIRE(l2[2] == 3);

    // // a deep copy: changing one must not change the other
    // l2[0] = 100;
    // REQUIRE(l[0] == 1);

    // SECTION("copy of an empty list") {
    //     List empty;
    //     List copy(empty);
    //     REQUIRE(copy.isEmpty());
    // }
}

// TEST_CASE("assignment", "[list]") {
//     List l;
//     l.append(1);
//     l.append(2);

//     List l2;
//     l2.append(9);
//     l2 = l;
//     REQUIRE(l2.getSize() == 2);
//     REQUIRE(l2.getFirst() == 1);
//     REQUIRE(l2.getLast() == 2);

//     // deep copy
//     l2[0] = 100;
//     REQUIRE(l[0] == 1);

//     SECTION("self-assignment") {
//         l = l;
//         REQUIRE(l.getSize() == 2);
//         REQUIRE(l.getFirst() == 1);
//     }
// }
