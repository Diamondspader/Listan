#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <memory>
#include <iterator>
#include <algorithm>

class List
{
private:
    class List_Iterator;
public:
    List();
    List(List const &);
    List(List &&) noexcept;
    List(std::initializer_list<int>);
    ~List();
    List & operator=(List const &)&;
    List & operator=(List &&)& noexcept;

    void push_front(int);
    void push_back(int);

    int back() const noexcept;
    int & back() noexcept;

    int front() const noexcept;
    int & front() noexcept;

    int & at(int idx);
    int const & at(int idx) const;

    int size() const noexcept;
    bool empty() const noexcept;

    void swap(List & other) noexcept;

    List_Iterator begin();
    List_Iterator end();


private:
    struct Node;
    std::unique_ptr<Node> head;
    Node * tail {};
    int sz {};


    class List_Iterator
    {
    public:
        List_Iterator(List::Node* curr);
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef int value_type;
        typedef int difference_type;
        typedef int* pointer;
        typedef int& reference;
		
        List_Iterator operator ++(int);
        List_Iterator& operator ++();
        List_Iterator  operator --(int);
        List_Iterator& operator --();
		
        reference operator *() const;
        bool operator ==(List_Iterator& other)const;
        bool operator !=(List_Iterator other)const;
    private:
        List::Node* current;
       
    };
	
    
};

#endif //LIST_H



