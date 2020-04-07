#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <memory>
#include <iterator>
#include <algorithm>

namespace List_NS
{
    template <typename T>
    class List
    {
    private:
        class List_Iterator;
    public:
        List();
        List(List const&);
        List(List&&) noexcept;
        List(std::initializer_list<T>);
        ~List();
        List& operator=(List const&)&;
        List& operator=(List&&)&noexcept;

        void push_front(T value);
        void push_back(T value);

        T back() const noexcept;
        T& back() noexcept;

        T front() const noexcept;
        T& front() noexcept;

        T& at(int idx);
        T const& at(int idx) const;

        int size() const noexcept;
        bool empty() const noexcept;

        void swap(List& other) noexcept;

        List_Iterator begin();
        List_Iterator end();


    private:
        struct Node;
        std::unique_ptr<Node> head;
        Node* tail{};
        int sz{};


        class List_Iterator
        {
        public:
            List_Iterator(List::Node* curr);
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef T value_type;
            typedef int difference_type;
            typedef T* pointer;
            typedef T& reference;

            List_Iterator operator ++(int);
            List_Iterator& operator ++();
            List_Iterator operator --(int);
            List_Iterator& operator --();

            reference operator *() const;
            pointer operator ->();
            bool operator ==(const List_Iterator& other)const;
            bool operator !=(const List_Iterator& other)const;
        private:
            List::Node* current;

        };


    };
}
#include "List.hpp"
#endif //LIST_H



