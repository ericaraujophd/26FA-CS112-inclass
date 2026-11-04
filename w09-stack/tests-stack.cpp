#define CATCH_CONFIG_MAIN
#include "Stack.h"
#include "Queue.h"
#include "catch.hpp"

#include <stdexcept>
#include <string>

using namespace std;

TEST_CASE("Stack constructor", "[stack][constructor]") {
    SECTION("a new stack is empty") {
        // TODO: isEmpty() is true, getSize() is 0
        Stack<int> s;
        REQUIRE(s.isEmpty());
        REQUIRE_THROWS_AS(s.pop(), underflow_error);
        REQUIRE_THROWS_AS(s.peekTop(), underflow_error);
    }
}

TEST_CASE("Stack push", "[stack][push]") {
    SECTION("push one item") {
        // TODO: size becomes 1, stack is no longer empty
        Stack<int> s;
        s.push(11);
        REQUIRE(s.getSize() == 1);
        REQUIRE(s.peekTop() == 11);
        REQUIRE(s.pop() == 11);
    }

    SECTION("push many items") {
        // TODO: size grows by one with every push
        Stack<int> s;
        s.push(1);
        s.push(2);
        REQUIRE(s.getSize() == 2);
        s.push(3);
        s.push(4);
        REQUIRE(s.getSize() == 4);
        s.push(5);
        REQUIRE(s.getSize() == 5);
        s.pop();
        REQUIRE(s.getSize() == 4);
        s.pop();
        s.pop();
        REQUIRE(s.getSize() == 2);

    }
}


TEST_CASE("Stack is LIFO", "[stack][lifo]") {
    SECTION("items come out in reverse order") {
        // TODO: push 1, 2, 3 -> pop gives 3, 2, 1
        Stack<int> s;
        s.push(1);
        s.push(2);
        s.push(3);
        REQUIRE(s.pop() == 3);
        REQUIRE(s.pop() == 2);
        REQUIRE(s.pop() == 1);
    }

    SECTION("interleaving push and pop") {
        // TODO: push 1, push 2, pop -> 2, push 3, pop -> 3, pop -> 1
        Stack<int> s;
        s.push(1);
        s.push(2);
        REQUIRE(s.pop() == 2);
        s.push(3);
        REQUIRE(s.pop() == 3);
        REQUIRE(s.pop() == 1);
        
    }
}

TEST_CASE("Stack after being emptied", "[stack][reuse]") {
    SECTION("popping everything leaves an empty stack") {
        // TODO: isEmpty() is true, pop throws again
        Stack<int> s;
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        REQUIRE(s.isEmpty());
        s.push(45);
        REQUIRE(!s.isEmpty());
    }

}

TEST_CASE("Queues"){
    SECTION("Constructor"){
        Queue<int> q;
        REQUIRE(q.getSize() == 0);
    }

    SECTION("Methods"){
        Queue<int> q;
        q.add(1);
        q.add(2);
        REQUIRE(q.getSize() == 2);
        REQUIRE(q.peekFront() == 1);
        REQUIRE(q.peekBack() == 2);
    }

    SECTION("Making students have nightmares"){
        Queue<Stack<string>> q;

        Stack<string> s1;
        Stack<string> s2;
        Stack<string> s3;

        s1.push("Catelyn");
        s1.push("Lucia");
        s1.push("Clara");
        s1.push("Ana Clara");
        s1.push("Kekeli");
        s1.push("Noelle");
        
        s2.push("Samuel");
        s2.push("Micaiah");
        s2.push("Marshall");
        
        s3.push("Caden");
        s3.push("Moses");
        s3.push("Elijah");
        s3.push("Kwesi");

        q.add(s1);
        q.add(s2);
        q.add(s3);

        REQUIRE(q.peekFront().peekTop() == "Noelle");
        REQUIRE(q.peekBack().peekTop() == "Kwesi");
        
        q.peekBack().pop();
        REQUIRE(q.peekBack().peekTop() == "Elijah");



    }
}
