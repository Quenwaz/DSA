#include "string.hpp"
#include <cstring>

using dsa::ds::String;

String::String(/* args */)
{
}

String::String(const String& inst)
{
    *this = String(inst.c_str());
}

String& String::operator=(const String& inst)
{
    if (&inst == this){
        return *this;
    }

    this->reserve(inst.size());
    size_ = inst.size();
    memcpy(dataptr_, inst.dataptr_, size_);
    return *this;
}

String::String(const char* psz)
{
    size_t len = 0;
    while((*psz) != '\0') {
        ++psz;
        ++len;
    }
    psz-=len;
    this->reserve(len + 1);
    memcpy(dataptr_, psz, len);
    size_ = len;
}

String::String(size_t size, const char& val)
    : Vector<char>(size, val)
{

}

String::~String()
{
}

const char* String::c_str() const
{
    return &dataptr_[0];
}


int String::find(const char* input)
{
    size_t i = 0;
    decltype(input) beg = input;
    decltype(input) pos = input;
    for (; i < size_ && *(pos) != '\0' ; ++i, ++pos){
        if ((*pos) != dataptr_[i]){
            if (i > 0)
                i = i - (pos- beg) + 1;
            pos = beg;
            
        }
    }

    if (*(pos) != '\0'){
        return -1; 
    }

    return i - (pos- beg);
}

int String::find(const String &input)
{
    return this->find(input.c_str());
}