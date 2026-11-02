#define CATCH_CONFIG_MAIN
#include "List.h"
#include "catch.hpp"

#include <stdexcept>
#include <string>

using namespace std;

// Helper: build a list holding the given values, in order, using append
List<int> makeList(initializer_list<int> values) {
    List<int> l;
    for (int it : values) {
        l.append(it);
    }
    return l;
}

TEST_CASE("default constructor", "[constructor]") {
    List<int> l;
    REQUIRE(l.getSize() == 0);
    REQUIRE(l.isEmpty());

    SECTION("getFirst and getLast throw on an empty list") {
        REQUIRE_THROWS_AS(l.getFirst(), underflow_error);
        REQUIRE_THROWS_AS(l.getLast(), underflow_error);
    }

    SECTION("indexing an empty list throws") {
        REQUIRE_THROWS_AS(l.getIndex(0), invalid_argument);
        REQUIRE_THROWS_AS(l[0], invalid_argument);
    }
}

TEST_CASE("append", "[append]") {
    List<int> l;

    SECTION("one item") {
        l.append(7);
        REQUIRE(l.getSize() == 1);
        REQUIRE_FALSE(l.isEmpty());
        REQUIRE(l.getFirst() == 7);
        REQUIRE(l.getLast() == 7);
    }

    SECTION("many items keep their order") {
        l.append(1);
        l.append(2);
        l.append(3);
        REQUIRE(l.getSize() == 3);
        REQUIRE(l.getFirst() == 1);
        REQUIRE(l.getLast() == 3);
        REQUIRE(l.getIndex(0) == 1);
        REQUIRE(l.getIndex(1) == 2);
        REQUIRE(l.getIndex(2) == 3);
    }
}

TEST_CASE("prepend", "[prepend]") {
    List<int> l;

    SECTION("one item") {
        l.prepend(7);
        REQUIRE(l.getSize() == 1);
        REQUIRE(l.getFirst() == 7);
        REQUIRE(l.getLast() == 7);
    }

    SECTION("many items end up in reverse order") {
        l.prepend(1);
        l.prepend(2);
        l.prepend(3);
        REQUIRE(l.getSize() == 3);
        REQUIRE(l.getFirst() == 3);
        REQUIRE(l.getLast() == 1);
        REQUIRE(l.getIndex(1) == 2);
    }

    SECTION("mixing prepend and append") {
        l.append(2);   // [2]
        l.prepend(1);  // [1, 2]
        l.append(3);   // [1, 2, 3]
        l.prepend(0);  // [0, 1, 2, 3]
        REQUIRE(l.getSize() == 4);
        for (unsigned i = 0; i < l.getSize(); i++) {
            REQUIRE(l[i] == (int)i);
        }
        REQUIRE(l.getFirst() == 0);
        REQUIRE(l.getLast() == 3);
    }
}

TEST_CASE("indexing", "[index]") {
    List<int> l = makeList({10, 20, 30, 40});

    SECTION("getIndex reads every position") {
        REQUIRE(l.getIndex(0) == 10);
        REQUIRE(l.getIndex(1) == 20);
        REQUIRE(l.getIndex(2) == 30);
        REQUIRE(l.getIndex(3) == 40);
    }

    SECTION("operator[] reads every position") {
        REQUIRE(l[0] == 10);
        REQUIRE(l[3] == 40);
    }

    SECTION("operator[] returns a reference, so we can write through it") {
        l[1] = 99;
        REQUIRE(l[1] == 99);
        REQUIRE(l.getIndex(1) == 99);
        l[0] = -1;
        l[3] = -4;
        REQUIRE(l.getFirst() == -1);
        REQUIRE(l.getLast() == -4);
    }

    SECTION("getIndex works on a const List") {
        const List<int>& cl = l;
        REQUIRE(cl.getIndex(2) == 30);
    }

    SECTION("indexes past the end throw out_of_range") {
        REQUIRE_THROWS_AS(l.getIndex(4), out_of_range);
        REQUIRE_THROWS_AS(l[4], out_of_range);
        REQUIRE_THROWS_AS(l[100], out_of_range);
    }
}

TEST_CASE("removeFirst", "[removeFirst]") {
    SECTION("empty list throws") {
        List<int> l;
        REQUIRE_THROWS_AS(l.removeFirst(), underflow_error);
    }

    SECTION("returns items from the front, in order") {
        List<int> l = makeList({1, 2, 3});
        REQUIRE(l.removeFirst() == 1);
        REQUIRE(l.getSize() == 2);
        REQUIRE(l.getFirst() == 2);
        REQUIRE(l.getLast() == 3);

        REQUIRE(l.removeFirst() == 2);
        REQUIRE(l.getSize() == 1);
        REQUIRE(l.getFirst() == 3);
        REQUIRE(l.getLast() == 3);

        REQUIRE(l.removeFirst() == 3);
        REQUIRE(l.getSize() == 0);
        REQUIRE(l.isEmpty());
        REQUIRE_THROWS_AS(l.removeFirst(), underflow_error);
    }

    SECTION("the list is still usable after being emptied") {
        List<int> l = makeList({5});
        l.removeFirst();
        l.append(6);
        REQUIRE(l.getSize() == 1);
        REQUIRE(l.getFirst() == 6);
        REQUIRE(l.getLast() == 6);
        l.removeFirst();
        l.prepend(7);
        l.append(8);
        REQUIRE(l.getFirst() == 7);
        REQUIRE(l.getLast() == 8);
    }
}

TEST_CASE("copy constructor", "[copy]") {
    SECTION("copy of an empty list is empty") {
        List<int> orig;
        List<int> copy(orig);
        REQUIRE(copy.getSize() == 0);
        REQUIRE(copy.isEmpty());
    }

    SECTION("copy has the same items in the same order") {
        List<int> orig = makeList({1, 2, 3});
        List<int> copy(orig);
        REQUIRE(copy.getSize() == 3);
        REQUIRE(copy.getFirst() == 1);
        REQUIRE(copy.getLast() == 3);
        for (unsigned i = 0; i < 3; i++) {
            REQUIRE(copy[i] == orig[i]);
        }
    }

    SECTION("copy is deep: changing one does not change the other") {
        List<int> orig = makeList({1, 2, 3});
        List<int> copy(orig);

        orig[0] = 100;
        REQUIRE(copy[0] == 1);

        copy.append(4);
        REQUIRE(copy.getSize() == 4);
        REQUIRE(orig.getSize() == 3);
        REQUIRE(orig.getLast() == 3);

        orig.removeFirst();
        REQUIRE(copy.getFirst() == 1);
    }

    SECTION("pass-by-value uses the copy constructor") {
        List<int> orig = makeList({4, 5, 6});
        auto sumByValue = [](List<int> l) {
            int total = 0;
            for (unsigned i = 0; i < l.getSize(); i++) total += l[i];
            return total;
        };
        REQUIRE(sumByValue(orig) == 15);
        REQUIRE(orig.getSize() == 3);  // original untouched
    }
}

TEST_CASE("assignment operator", "[assign]") {
    SECTION("assign a non-empty list to an empty list") {
        List<int> a;
        List<int> b = makeList({1, 2, 3});
        a = b;
        REQUIRE(a.getSize() == 3);
        REQUIRE(a.getFirst() == 1);
        REQUIRE(a.getLast() == 3);
        REQUIRE(a[1] == 2);
    }

    SECTION("assign over a list that already has items") {
        List<int> a = makeList({9, 9, 9, 9, 9});
        List<int> b = makeList({1, 2});
        a = b;
        REQUIRE(a.getSize() == 2);
        REQUIRE(a.getFirst() == 1);
        REQUIRE(a.getLast() == 2);
    }

    SECTION("assign an empty list") {
        List<int> a = makeList({1, 2, 3});
        List<int> b;
        a = b;
        REQUIRE(a.getSize() == 0);
        REQUIRE(a.isEmpty());
        REQUIRE_THROWS_AS(a.getFirst(), underflow_error);
    }

    SECTION("assignment is deep") {
        List<int> a;
        List<int> b = makeList({1, 2, 3});
        a = b;
        b[0] = 100;
        b.append(4);
        REQUIRE(a[0] == 1);
        REQUIRE(a.getSize() == 3);
        REQUIRE(a.getLast() == 3);
    }

    SECTION("self-assignment leaves the list unchanged") {
        List<int> a = makeList({1, 2, 3});
        List<int>& alias = a;  // avoids a -Wself-assign warning
        a = alias;
        REQUIRE(a.getSize() == 3);
        REQUIRE(a.getFirst() == 1);
        REQUIRE(a.getLast() == 3);
    }

    SECTION("assignment can be chained") {
        List<int> a, b;
        List<int> c = makeList({7, 8});
        a = b = c;
        REQUIRE(a.getSize() == 2);
        REQUIRE(b.getSize() == 2);
        REQUIRE(a.getLast() == 8);
        REQUIRE(b.getFirst() == 7);
    }
}

TEST_CASE("removeLast", "[removeLast]") {
    SECTION("empty list throws") {
        List<int> l;
        REQUIRE_THROWS_AS(l.removeLast(), underflow_error);
    }

    SECTION("single item list becomes empty") {
        List<int> l = makeList({42});
        REQUIRE(l.removeLast() == 42);
        REQUIRE(l.getSize() == 0);
        REQUIRE(l.isEmpty());
        l.append(1);  // still usable
        REQUIRE(l.getFirst() == 1);
        REQUIRE(l.getLast() == 1);
    }

    SECTION("two items") {
        List<int> l = makeList({1, 2});
        REQUIRE(l.removeLast() == 2);
        REQUIRE(l.getSize() == 1);
        REQUIRE(l.getFirst() == 1);
        REQUIRE(l.getLast() == 1);
    }

    SECTION("returns items from the back, in reverse order") {
        List<int> l = makeList({1, 2, 3, 4});
        REQUIRE(l.removeLast() == 4);
        REQUIRE(l.getLast() == 3);
        REQUIRE(l.getSize() == 3);
        REQUIRE(l.removeLast() == 3);
        REQUIRE(l.removeLast() == 2);
        REQUIRE(l.removeLast() == 1);
        REQUIRE(l.isEmpty());
    }

    SECTION("append after removeLast links to the right node") {
        List<int> l = makeList({1, 2, 3});
        l.removeLast();
        l.append(30);
        REQUIRE(l.getSize() == 3);
        REQUIRE(l[0] == 1);
        REQUIRE(l[1] == 2);
        REQUIRE(l[2] == 30);
    }
}

// List is a template, so the same code works for any Item type
TEST_CASE("List works with other Item types", "[template]") {
    SECTION("List<double>") {
        List<double> l;
        l.append(2.5);
        l.prepend(1.5);
        REQUIRE(l.getSize() == 2);
        REQUIRE(l.getFirst() == 1.5);
        REQUIRE(l.getLast() == 2.5);
        REQUIRE(l.removeLast() == 2.5);
    }

    SECTION("List<string>") {
        List<string> l;
        l.append("world");
        l.prepend("hello");
        REQUIRE(l[0] == "hello");
        REQUIRE(l[1] == "world");

        List<string> copy(l);  // copies are deep for strings too
        l[0] = "goodbye";
        REQUIRE(copy[0] == "hello");

        REQUIRE(l.removeFirst() == "goodbye");
        REQUIRE(l.getSize() == 1);
    }

    SECTION("List of Lists") {
        List<List<int>> grid;
        grid.append(makeList({1, 2}));
        grid.append(makeList({3, 4, 5}));
        REQUIRE(grid.getSize() == 2);
        REQUIRE(grid[1].getSize() == 3);
        REQUIRE(grid[1][2] == 5);
    }
}

// remove(int) and operator== are declared in List.h but not defined yet.
// Add tests for them once they exist.
