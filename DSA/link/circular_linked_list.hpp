#ifndef __INCLUDE_LINK_H___
#define __INCLUDE_LINK_H___
#include <stddef.h>

namespace dsa::ds{

template <typename DataType>
struct LinkNode{
    DataType data;
    LinkNode* next;
};

template <typename DataType>
class CircledList
{

public:
    explicit CircledList(size_t capacity=0);
    ~CircledList();
    size_t size() const;
    bool empty() const;
    bool isfull() const;
    LinkNode<DataType>* top();

    void pop();
    void push(const DataType& val);
private:
    LinkNode<DataType>* tail_;
    size_t size_;
    size_t capacity_;
};



template <class DataType> CircledList<DataType>::CircledList(size_t capacity)
    : tail_(nullptr), size_(0),capacity_(capacity)
{
}

template <class DataType> CircledList<DataType>::~CircledList()
{
    for(;!this->empty();){
        this->pop();
    }
}


template <class DataType> 
size_t CircledList<DataType>::size() const
{
    return size_;
}

template <class DataType> 
bool CircledList<DataType>::empty() const
{
    return size_ == 0;
}

template <class DataType> 
bool CircledList<DataType>::isfull() const
{
    return (capacity_ > 0 && capacity_ == size_);
}

template <class DataType> 
LinkNode<DataType>* CircledList<DataType>::top()
{
    if (this->tail_ == nullptr){
        return nullptr;
    }
    return this->tail_->next;
}

template <class DataType> 
void CircledList<DataType>::pop()
{
    if (this->tail_ == nullptr){
        return;
    }

    auto head = this->tail_->next;
    this->tail_->next = head->next;
    if(head == this->tail_){
        this->tail_ = nullptr;
    }
    --size_;
    delete head;
}

template <class DataType> 
void CircledList<DataType>::push(const DataType& val)
{
    LinkNode<DataType>* node = new LinkNode<DataType>();
    node->next = nullptr;
    node->data = val;

    if (this->tail_ == nullptr){
        this->tail_ = node;
        this->tail_->next = node;
    }
    else{
        node->next = this->tail_->next;
        this->tail_->next = node;
        this->tail_ = node;
    }
    ++this->size_;
}

}



#endif // __INCLUDE_LINK_H___