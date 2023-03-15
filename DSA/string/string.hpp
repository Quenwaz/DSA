#ifndef __H_STRING_INCLUDED__
#define __H_STRING_INCLUDED__
#include "DSA/vector/vector.hpp"


namespace dsa::ds
{
    class String: public Vector<char>
    {
    public:
        String(/* args */);
        String(const String& inst);
        String& operator=(const String& inst);
        explicit String(const char* psz);
        String(size_t size, const char& val);
        ~String();

    public:
        int find(const char* input);
        int find(const String& input);
        int index_KMP(const char* input);
        const char* c_str() const;
    };
    

    
}


#endif // __H_STRING_INCLUDED__