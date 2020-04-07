#include "List.h"
#include <iterator>
#include <utility>
#include <stdexcept>
#include <memory>

using namespace List_NS;
template <typename T>
struct List<T>::Node
{
    Node() = default;
    Node(T v, Node* p, std::unique_ptr<Node> n)
        : value{ v }, prev{ p }, next{ std::move(n) }{}
    ~Node() = default;
    T value{};
    Node* prev{};
    std::unique_ptr<Node> next{};
};

template <typename T>
List<T>::List()
    : head{ std::make_unique<Node>() }, tail{}, sz{}
{
    head->next = std::make_unique<Node>(T{}, head.get(), nullptr);
    tail = head->next.get();
}
template <typename T>
List<T>::~List<T>() {}

template <typename T>
List<T>::List(List const& other)
    : List{}
{
    for (Node* tmp{ other.head->next.get() }; tmp != other.tail; )
    {
        push_back(tmp->value);
        tmp = tmp->next.get();
    }
}
template <typename T>
List<T>::List(List&& tmp) noexcept
    :List{}
{
    swap(tmp);
}
template <typename T>
List<T>::List(std::initializer_list<T> lst)
    : List{}
{
    for (auto val : lst)
    {
        push_back(val);
    }
}
template <typename T>
void List<T>::push_front(T value)
{
    Node* old_first{ head->next.get() };
    head->next = std::make_unique<Node>(value, head.get(), std::move(head->next));
    old_first->prev = head->next.get();
    ++sz;
}
template <typename T>
void List<T>::push_back(T value)
{
    Node* old_last{ tail->prev };
    old_last->next = std::make_unique<Node>(value, old_last, std::move(old_last->next));
    tail->prev = old_last->next.get();
    ++sz;
}
template <typename T>
bool List<T>::empty() const noexcept
{
    return head->next.get() == tail;
}
template <typename T>
T List<T>::back() const noexcept
{
    return tail->prev->value;
}
template <typename T>
T& List<T>::back() noexcept
{
    return tail->prev->value;
}
template <typename T>
T List<T>::front() const noexcept
{
    return head->next->value;
}
template <typename T>
T& List<T>::front() noexcept
{
    return head->next->value;
}
template <typename T>
T& List<T>::at(int idx)
{
    return const_cast<int&>(static_cast<List const*>(this)->at(idx));

}
template <typename T>
T const& List<T>::at(int idx) const
{
    if (idx >= sz)
        throw std::out_of_range{ "Index not found" };
    Node* tmp{ head->next.get() };
    while (idx > 0)
    {
        tmp = tmp->next.get();
        --idx;
    }
    return tmp->value;
}
template <typename T>
int List<T>::size() const noexcept
{
    return sz;
}
template <typename T>
void List<T>::swap(List& other) noexcept
{
    using std::swap;
    swap(head, other.head);
    swap(tail, other.tail);
    swap(sz, other.sz);
}
template <typename T>
List<T>& List<T>::operator=(List const& rhs)&
{
    List{ rhs }.swap(*this);
    return *this;
}
template <typename T>
List<T>& List<T>::operator=(List&& rhs) & noexcept
{
    swap(rhs);
    return *this;
}
template <typename T>
List<T>::List_Iterator::List_Iterator(Node* curr) :
    current{ curr }
{

}
template <typename T>
typename List<T>::List_Iterator List<T>::begin()
{
    return List_Iterator{ head->next.get() };
}
template <typename T>
typename List<T>::List_Iterator List<T>::end()
{
    return List_Iterator{ tail };
}
template <typename T>
typename List<T>::List_Iterator List<T>::List_Iterator::operator++(int)
{
    List_Iterator tmp{ *this };
    current = current->next.get();
    return  tmp;
}
template <typename T>
typename List<T>::List_Iterator& List<T>::List_Iterator::operator++()
{
    current = current->next.get();
    return *this;
}
template <typename T>
typename List<T>::List_Iterator List<T>::List_Iterator::operator--(int)
{
    List_Iterator tmp{ *this };
    current = current->prev;
    return tmp;
}
template <typename T>
typename List<T>::List_Iterator& List<T>::List_Iterator::operator--()
{
    current = current->prev;
    return *this;
}
template <typename T>
T& List<T>::List_Iterator::operator*() const
{
    return current->value;
}

template <typename T>
T* List<T>::List_Iterator::operator->() 
{
    return &(current->value);
}

template <typename T>
bool List<T>::List_Iterator::operator==(const List_Iterator& other)const
{
    return current == other.current;
}
template <typename T>
bool List<T>::List_Iterator::operator!=(const List_Iterator& other) const
{
    return !(*this == other);
}

