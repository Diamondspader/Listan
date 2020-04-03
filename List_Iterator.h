#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include <iterator>
#include <algorithm>

class List_Iterator
{
public:
	typedef std::bidirectional_iterator_tag iterator_category;
	typedef int value_type;
	typedef int difference_type;
	typedef int* pointer;
	typedef int& reference;
	
	List_Iterator  operator ++(int);
	List_Iterator & operator ++();
	List_Iterator  operator --(int);
	List_Iterator & operator --();

	int & operator *();
	bool & operator ==(List_Iterator other)const;
	bool & operator !=(List_Iterator other)const;
private:

};

#endif