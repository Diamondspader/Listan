
#include "List.h"

#include "catch.hpp"
#include <iostream>

TEST_CASE( "Create list" )
{
 for (int i = 0; i < 50000; i++) {
    List lst{ 1,4,2,6,8,9 };
    CHECK(lst.at(2) == 2);
    lst.at(2) = 3;
    CHECK(lst.at(2) == 3);
    CHECK(lst.size() == 6);
    List l2;
    l2 = lst;
    CHECK(l2.size() == lst.size());
    CHECK(l2.front() == lst.front());
    CHECK(l2.back() == lst.back());
    
    List l3 = l2;
    CHECK(l3.size() == lst.size());
    CHECK(l3.front() == lst.front());
    CHECK(l3.back() == lst.back());

    List l4{11, 13};
    l4.swap(lst);
    CHECK(lst.front() == 11);
    CHECK(lst.back() == 13);
    CHECK(l4.size() == l3.size());
    CHECK(l4.front() == l3.front());
    CHECK(l4.back() == l3.back());

    lst.push_back(99);
    lst.push_front(1);
	CHECK(lst.front() == 1);
    CHECK(lst.back() == 99);

    List l5 = std::move(l4);
	CHECK(l5.size() == l3.size());
    CHECK(l5.front() == l3.front());
    CHECK(l5.back() == l3.back());
    CHECK(l4.size() == 0);
    List l6;
    l6 = std::move(l5);
    CHECK(l6.size() == l3.size());
    CHECK(l6.front() == l3.front());
    CHECK(l6.back() == l3.back());
    CHECK(l5.size() == 0);
	}
 int x;
 std::cin >> x;
}

