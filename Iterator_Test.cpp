#include "List.h"
#include "catch.hpp"
#include <iostream>
#include <memory>
#include <iterator>

TEST_CASE( "Create list" )
{

	 List lst{ 2,3,1,5 };
        auto rb{ std::make_reverse_iterator(lst.end()) };
        auto re{ std::make_reverse_iterator(lst.begin()) };
        for (auto it = rb; it != re; ++it)
        {
            std::cout << *it << ' ';
        }
        std::cout << std::endl;
	
	//auto rb{ make_reverse_iterator(1st.end()) };



	
}