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


void get_next(const char* pattern, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while(pattern[i] != '\0')
    {
        if (j == 0 || pattern[i]  == pattern[j]){
            ++i;
            ++j;
            next[i] = j;
        }else
            j = next[j];
    }
}

int String::index_KMP(const char* input)
{
    int i = 0, j = 1;
    decltype(input) beg = input;
    size_t len = strlen(input);
    int next[len + 1] ={0};
    get_next(input, next);
    for(;(*input) != '\0' && i != size_; )
    {
        if (j == 0 || (*input) == dataptr_[i]){
            ++i;
            ++input;
        }else 
            input = beg + next[input - beg];
    }

    if (*(input) != '\0'){
        return -1; 
    }

    return i - (input- beg);
}