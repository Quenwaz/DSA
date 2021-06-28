#ifndef _h_link_incluede__
#define _h_link_incluede__
#include <stddef.h>

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
private:
    LinkNode<_Tp>* root_;
    LinkNode<_Tp>* curpos_;
    size_t size_;
};

template <class _Tp> Link<_Tp>::Link()
    : root_(nullptr), curpos_(nullptr), size_(0)
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
    return this->curpos_->value;
}

template <class _Tp> void Link<_Tp>::pop_back()
{
    if (this->empty()){
        return;
    }

    LinkNode<_Tp>* curnode = this->curpos_;
    if (this->curpos_->previous == nullptr){
        this->curpos_ = nullptr;
        this->root_ = nullptr;
    }else
        this->curpos_->previous->next = nullptr;

    --this->size_;
    delete curnode;
}

template <class _Tp> void Link<_Tp>::push_back(const _Tp& val)
{
    LinkNode<_Tp>* node = new LinkNode<_Tp>();
    node->next = nullptr;
    node->value = val;
    node->previous = this->curpos_;

    if (this->root_ == nullptr){
        this->root_ = node;
        this->curpos_ = this->root_;
    }

    this->curpos_->next_ = node;
    ++this->size_;
}


#endif // _h_link_incluede__