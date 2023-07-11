#ifndef _h_link_incluede__
#define _h_link_incluede__
#include <stddef.h>
#include <queue>

namespace dsa::ds{
template <typename DataType>
struct LinkNode{
    DataType data;
    LinkNode* previous;
    LinkNode* next;
};


template <class DataType>
class Link{
public:
    Link();
    ~Link();
    size_t size() const;
    bool empty() const;
    DataType& front();
    DataType& back();

    LinkNode<DataType>* operator[](size_t idx) const;
    void pop_back();
    void push_back(const DataType& val);
    void pop_front();
    void push_front(const DataType& val);
    bool insert(size_t npos, const DataType& val);
    bool remove(LinkNode<DataType>* node);
    void reverse();
    void rearrangement();
private:
    LinkNode<DataType>* head_;
    LinkNode<DataType>* tail_;
    size_t size_;
};

template <class DataType> Link<DataType>::Link()
    : head_(nullptr), tail_(nullptr), size_(0)
{
}

template <class DataType> Link<DataType>::~Link()
{
    for(;!this->empty();){
        this->pop_back();
    }
}


template <class DataType> size_t Link<DataType>::size() const
{
    return size_;
}

template <class DataType> bool Link<DataType>::empty() const 
{
    return this->size() == 0;
}

template <class DataType> DataType& Link<DataType>::front()
{
    return this->head_->data;
}

template <class DataType> DataType& Link<DataType>::back()
{
    return this->tail_->data;
}


template <class DataType>
LinkNode<DataType>* Link<DataType>::operator[](size_t idx) const
{
    if (idx >= size_){
        return nullptr;
    }

    LinkNode<DataType>* node = this->head_;
    for (size_t i = 1;i <= idx; ++i)
    {
        node = node->next;
    }

    return node;
}

template <class DataType> 
bool Link<DataType>::remove(LinkNode<DataType>* node)
{
    if(node == nullptr){
        return false;
    }

    if (node->next != nullptr){
        node->next->previous = node->previous;
    }

    if (node == this->tail_){
        this->tail_ = node->previous;
        if(this->tail_!= nullptr)
            this->tail_->next = nullptr;
    }
    else
        node->previous = node->next;

    if(node == this->head_){
        this->head_ = node->next;
        if(this->head_ != nullptr)
            this->head_->previous = nullptr;
    }

    --this->size_;
    delete node;
    return true;
}


template <class DataType> void Link<DataType>::pop_back()
{
    if (this->empty()){
        return;
    }

    LinkNode<DataType>* curnode = this->tail_;
    if (this->tail_->previous == nullptr){
        this->tail_ = nullptr;
        this->head_ = nullptr;
    }else{
        this->tail_->previous->next = nullptr;
        this->tail_ = this->tail_->previous;
    }

    --this->size_;
    delete curnode;
}

template <class DataType> void Link<DataType>::push_back(const DataType& val)
{
    LinkNode<DataType>* node = new LinkNode<DataType>();
    node->next = nullptr;
    node->data = val;
    node->previous = this->tail_;

    if (this->head_ == nullptr){
        this->head_ = node;
        this->tail_ = this->head_;
    }
    else{
        this->tail_->next = node;
        this->tail_ = node;
    }
    ++this->size_;
}

template <class DataType> 
void Link<DataType>::pop_front()
{
    if (this->empty()){
        return;
    }

    LinkNode<DataType>* curnode = this->head_;
    if (this->head_->next == nullptr){
        this->head_ = nullptr;
        this->tail_ = nullptr;
    }else{
        this->head_->next->previous = nullptr;
        this->head_ = this->head_->next;
    }

    --this->size_;
    delete curnode;
}

template <class DataType> 
void Link<DataType>::push_front(const DataType& val)
{
    LinkNode<DataType>* node = new LinkNode<DataType>();
    node->next = this->head_;
    node->data = val;
    node->previous = nullptr;

    if (this->head_ == nullptr){
        this->head_ = node;
        this->tail_ = this->head_;
    }
    else{
        this->head_->previous = node;
        this->head_ = node;
    }
    ++this->size_;
}

template <class DataType>
bool Link<DataType>::insert(size_t npos, const DataType& val)
{
    if (npos > size_){
        return false;
    }

    LinkNode<DataType>* node = new LinkNode<DataType>();
    node->next = nullptr;
    node->data = val;
    if (this->head_ == nullptr){
        this->head_ = node;
    }
    else{
        LinkNode<DataType>* curnode = this->head_;
        for (size_t i = 1; i < npos; ++i){
            curnode = curnode->next;
        }

        if (npos == 0){
            this->head_->previous = node;
            node->next = this->head_;
            this->head_ = node;
        }else{
            node->previous = curnode;
            node->next = curnode->next;
            curnode->next = node;
        }
    }

    if (node->next == nullptr){
        this->tail_ = node;
    }

    ++this->size_;
    return true;
}

template <class DataType> void Link<DataType>::rearrangement()
{
    std::queue<LinkNode<DataType>*> queue_odd;
    queue_odd.push(this->head_);
    LinkNode<DataType>* odd = this->head_;
    LinkNode<DataType>* even = odd->next;
    LinkNode<DataType>* even_pos = even;
    for (;even_pos != nullptr && even_pos->next != nullptr;)
    {
        odd->next = even_pos->next;
        auto previous_odd = odd;
        odd = odd->next;
        odd->previous = previous_odd;
        even_pos->next = odd->next;
        if (even_pos->next == nullptr){
            break;
        }
        auto previous_even = even_pos;
        even_pos = even_pos->next;
        if (even_pos != nullptr)
            even_pos->previous = previous_even;
    }
    even->previous = odd;
    odd->next = even;
    this->tail_ = even_pos;
}

template <class DataType> void Link<DataType>::reverse()                                                           
{
    LinkNode<DataType>* nnext = nullptr;
    for (LinkNode<DataType>* curpos = this->head_;curpos != nullptr; )
    {
        LinkNode<DataType>* next =  curpos->next;
        if (nnext != nullptr)
        {
            next = nnext;
        }else{
            curpos->next = nullptr;
        }

        nnext = next->next;
        next->next= curpos;
        curpos->previous = next;
        curpos = next;
        if(nnext == nullptr){
            curpos->previous = nullptr;
            break;
        }
    }
    std::swap(this->head_, this->tail_);
}

}
#endif // _h_link_incluede__