#ifndef _h_vector_incluede__
#define _h_vector_incluede__
#include <cstddef>
#include <exception>

namespace dsa::ds{


template <class T>
class Vector
{
private:
    size_t size_;
    size_t capacity_;
    T* dataptr_;
private:
    void initial_value(const T& val);
public:
    Vector();
    Vector(size_t size, const T& val);
    ~Vector();

public:
    void push_back(const T& val);
    void pop_back();
    void resize(size_t size);
    size_t size() const;
    bool empty() const;
    void clear();
    void shrift_to_fit();
    const T& operator[](size_t pos) const;
    T& at(size_t pos);
    bool remove(size_t pos);

};

template<class T>
Vector<T>::Vector()
    : size_(0), capacity_(0), dataptr_(nullptr)
{
}

template<class T>
Vector<T>::Vector(size_t size, const T& val)
    : size_(size), capacity_(size), dataptr_(new T[capacity_])
{
    initial_value(val);
}

template<class T>
Vector<T>::~Vector()
{
    clear();
}

template<class T>
void Vector<T>::initial_value(const T& val){

    for (size_t i = 0;i < size_; ++i)
        dataptr_[i] = val;
}

template<class T>
void Vector<T>::push_back(const T& val)
{
    if (size_ >= capacity_){
        T* __tmp = new T[capacity_*2];
        for (size_t i =0; i< size_; ++i)
            __tmp[i] = dataptr_[i];
        delete [] dataptr_;
        dataptr_ = __tmp;
    }
    dataptr_[size_] = val;
    ++size_;
}

template<class T>
void Vector<T>::pop_back()
{
    remove(size_ - 1);
}

template<class T>
void Vector<T>::resize(size_t size)
{
    if (size <= 0){
        return;
    }

    delete []dataptr_;
    dataptr_ = new T[size]{0};
    capacity_ = size;
    size_ = size;
}

template<class T>
size_t Vector<T>::size() const
{
    return size_;
}

template<class T>
bool Vector<T>::empty() const
{
    return size_ == 0;
}

template<class T>
void Vector<T>::clear()
{
    delete [] dataptr_;
    dataptr_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

template<class T>
T& Vector<T>::at(size_t pos)
{
    if (pos >= size_){
        return T();
    }

    return dataptr_[pos];
}

template<class T>
const T& Vector<T>::operator[](size_t pos) const
{
    if (pos >= size_){
        throw std::exception("out of range");
    }

    return dataptr_[pos];
}


template<class T>
bool Vector<T>::remove(size_t pos)
{
    if (pos >= size_){
        return false;
    }

    for (size_t i  = pos; i < (size_ - 1); ++i){
        dataptr_[i+1] = dataptr_[i];
    }

    --size_;
    return true;
}
}

#endif // _h_vector_incluede__