#define CATCH_CONFIG_MAIN
#include "PyList.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("PyList", "[pylist]") {
    SECTION("default constructor") {
        PyList<int> p;  // default constructor
        REQUIRE(p.getCapacity() == 0);
        REQUIRE(p.getSize() == 0);
    }

    SECTION("append") {
        PyList<int> p;
        p.append(5);
        p.append(9);
        REQUIRE(p.getCapacity() == 2);
        REQUIRE(p.getSize() == 2);
    }
    // Prof. Araújo realized nothing is removing items from the list... how dumb
}

TEST_CASE("indexing"){
    PyList<int> p;
    p.append(3); // 0
    p.append(4); // 1
    p.append(5); // 2
    p.append(15); // 3
    p.append(12); // 4
    p.append(-9);
    p.append(45);
    p.append(0);
    REQUIRE(p.getCapacity() == 8);
    REQUIRE(p.getSize() == 8);
    
    p.append(67);
    REQUIRE(p.getCapacity() == 16);
    REQUIRE(p.getSize() == 9);

    REQUIRE (p[2] == 5);
    REQUIRE (p.getIndex(2) == 5);
    REQUIRE (p[3] == 15);
    REQUIRE (p[4] == 12);
    REQUIRE (p[8] == 67);
    REQUIRE_THROWS_AS (p.getIndex(-1), invalid_argument);
    REQUIRE_THROWS_AS (p[-1], invalid_argument);
    REQUIRE_THROWS_AS (p[100], invalid_argument);
    
    p[3] = -5;
    REQUIRE (p[3] == -5);
}

TEST_CASE("copy constructor"){
    PyList<int> p;
    p.append(3); // 0
    p.append(4); // 1
    p.append(5); // 2
    p.append(15); // 3
    p.append(12); // 4
    p.append(-9); // 5
    p.append(45); // 6
    p.append(0);  // 7
    p.append(67); // 8

    // PyList p2 = p;
    PyList<int> p2(p);
    
    REQUIRE(p2.getCapacity() == 16);
    REQUIRE(p2.getSize() == 9);
}

TEST_CASE("template class"){
    PyList<string> students;
    students.append("Kwesi");
    students.append("Noelle");
    students.append("Samuel");
    REQUIRE(students.getSize() == 3);
    REQUIRE(students[0] == "Kwesi");
    REQUIRE(students[2] == "Samuel");
}

