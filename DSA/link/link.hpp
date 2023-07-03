#ifndef _h_link_incluede__
#define _h_link_incluede__
#include <stddef.h>

namespace dsa::ds{
template <typename _Tp>
struct LinkNode{
    _Tp value;
    LinkNode* previous;
    LinkNode* next;
};


template <class _Tp>
class Link{
public:
    Link();
    ~Link();
    size_t size() const;
    bool empty() const;
    _Tp& back();
    void pop_back();
    void push_back(const _Tp& val);
    void reverse();
private:
    LinkNode<_Tp>* head_;
    LinkNode<_Tp>* tail_;
    size_t size_;
};

template <class _Tp> Link<_Tp>::Link()
    : head_(nullptr), tail_(nullptr), size_(0)
{
}

template <class _Tp> Link<_Tp>::~Link()
{
    for(;!this->empty();){
        this->pop_back();
    }
}


template <class _Tp> size_t Link<_Tp>::size() const
{
    return size_;
}

template <class _Tp> bool Link<_Tp>::empty() const 
{
    return this->size() == 0;
}

template <class _Tp> _Tp& Link<_Tp>::back()
{
    return this->tail_->value;
}

template <class _Tp> void Link<_Tp>::pop_back()
{
    if (this->empty()){
        return;
    }

    LinkNode<_Tp>* curnode = this->tail_;
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

template <class _Tp> void Link<_Tp>::push_back(const _Tp& val)
{
    
    LinkNode<_Tp>* node = new LinkNode<_Tp>();
    node->next = nullptr;
    node->value = val;
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

template <class _Tp> void Link<_Tp>::reverse()
{
    LinkNode<_Tp>* nnext = nullptr;
    for (LinkNode<_Tp>* curpos = this->head_;curpos != nullptr; )
    {
        LinkNode<_Tp>* next =  curpos->next;
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