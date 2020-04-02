
#include "List.h"

#include "catch.hpp"
#include <iostream>

TEST_CASE( "Create list" )
{
   for (int i = 0; i <= 1000000; i++) {
    List lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    lst.at(2) = 3;
    CHECK(lst.at(2) == 3);
    CHECK(lst.size() == 6);
    List l2;
    l2 = lst;
    CHECK(l2.size() == lst.size());
    CHECK(l2.front() == lst.front());
    CHECK(l2.back() == lst.back());

    }
   int x;
   std::cin >> x;
}

