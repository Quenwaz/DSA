#include "queue_of_circle.hpp"

using dsa::ds::queue::QueueCircleLink;

template <typename T>
QueueCircleLink<T>::QueueCircleLink()
{

}

template <typename T>
void QueueCircleLink<T>::enque(const T& data)
{
    LinkNode* _new_node = nullptr;
    if (rear_ == nullptr){
        _new_node = new LinkNode();
        rear_ = _new_node;
    }else{

    }

    rear_->data = data;
}



template <typename T>
bool QueueCircleLink<T>::deque(T& data)
{
    return false;
}

