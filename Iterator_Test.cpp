#include "List.h"
#include "catch.hpp"
#include <iostream>
#include <memory>
#include <iterator>
#include <string>


TEST_CASE( "Create list" )
{

	    List_NS::List<std::string> lst{ "first", "mitt", "sista" };
        auto rb{ std::make_reverse_iterator(lst.end()) };
        auto re{ std::make_reverse_iterator(lst.begin()) };
        for (auto it = rb; it != re; ++it)
        {
            std::cout << it->length() << ' ';
        }
        std::cout << std::endl;
        

	    List_NS::List<int> list2 { 1, 2, 3,5 };
        auto rb2{ std::make_reverse_iterator(list2.end()) };
        auto re2{ std::make_reverse_iterator(list2.begin()) };
        for (auto it = rb2; it != re2; ++it)
        {
            std::cout << *it << ' ';
        }
        std::cout << std::endl;
	

         List_NS::List<double> list3 { 1.3, 2.3, 3.4,5.5 };
        auto rb3{ std::make_reverse_iterator(list3.end()) };
        auto re3{ std::make_reverse_iterator(list3.begin()) };
        for (auto it = rb3; it != re3; ++it)
        {
            std::cout << *it << ' ';
        }
        std::cout << std::endl;

		List_NS::List<char> list4{ 'a', 'b', 'k' };
        auto rb4{ list4.begin() };
        auto re4{ list4.end() };
        for (auto it = rb4; it != re4; ++it)
        {
            std::cout << *it << ' ';
        }
        std::cout << std::endl;

       class List
        {

        };

       List list999;
	
}