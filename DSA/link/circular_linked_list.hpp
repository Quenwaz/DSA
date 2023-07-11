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
    CircledList(/* args */);
    ~CircledList();
    size_t size() const;
    bool empty() const;
    LinkNode<DataType>* top();

    void pop();
    void push(const DataType& val);
private:
    LinkNode<DataType>* tail_;
    size_t size_;
};



template <class DataType> CircledList<DataType>::CircledList()
    : tail_(nullptr), size_(0)
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
    if (head == nullptr){
        head = this->tail_;
    }
    this->tail_->next = head->next;
    delete head;
    --size_;

    if(size_ == 0){
        this->tail_ = nullptr;
    }
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