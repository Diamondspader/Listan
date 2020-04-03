#include "List_Iterator.h"
#include <iterator>
#include <algorithm>

List_Iterator List_Iterator::operator++(int)
{
	return List_Iterator();
}

List_Iterator& List_Iterator::operator++()
{
	// TODO: insert return statement here
}

List_Iterator List_Iterator::operator--(int)
{
	return List_Iterator();
}

List_Iterator& List_Iterator::operator--()
{
	// TODO: insert return statement here
}


int & List_Iterator::operator *()
{
	//return reference;
}

bool& List_Iterator::operator==(List_Iterator other) const
{
	// TODO: insert return statement here
}

bool& List_Iterator::operator!=(List_Iterator other) const
{
	// TODO: insert return statement here
}
