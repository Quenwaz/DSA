#ifndef __DSA_STACK_HPP_
#define __DSA_STACK_HPP_
#include <cstddef>
#include "../vector/vector.hpp"

namespace dsa::ds{
template<class T>
class Stack
{
private:
    Vector<T>  vector_;
public:
    Stack();
    ~Stack();
    void push(const T& val);
    bool pop();
    const T& top() const;
    bool empty() const;
    size_t size() const;
};


template<class T>
Stack<T>::Stack()
{
}

template<class T>
Stack<T>::~Stack()
{
    vector_.clear();
}

template<class T>
void Stack<T>::push(const T& val)
{
    vector_.push_back(val);
}

template <class T>
bool Stack<T>::pop() 
{
    vector_.pop_back();
}

template<class T>
const T& Stack<T>::top() const 
{
    if (vector_.empty()){
        throw std::out_of_range("stack is empty");
    }

    return vector_[vector_.size() - 1];
}

template <class T>
bool Stack<T>::empty() const {
    return vector_.empty();
}
template <class T>
size_t Stack<T>::size() const {
    return vector_.size();
}
}  // namespace dsa::ds

#endif 