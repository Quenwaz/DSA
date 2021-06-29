#ifndef _h_mergesort_included
#define _h_mergesort_included
#include <functional>
#include <vector>
#include "../common/utils.h"

namespace dsa::alg::sort
{
    namespace __internal{
        template <typename ForwardIterator, typename Pred>
        void merge(ForwardIterator beg, ForwardIterator mid, ForwardIterator end, Pred pred )
        {
            std::vector<typename ForwardIterator::value_type> arraytmp;
            arraytmp.reserve(std::distance(beg, end)); 
            ForwardIterator iterl = beg, iterr = mid;
            for(;iterl != mid && iterr != end;)
            {
                if(pred(*iterl, *iterr)){
                    arraytmp.push_back(*iterl);
                    ++iterl;
                }else{
                    arraytmp.push_back(*iterr);
                    ++iterr;
                }
            }

            while (iterl != mid)
            {
                arraytmp.push_back(*iterl);
                ++iterl;
            }

            while (iterr != end)
            {
                arraytmp.push_back(*iterr);
                ++iterr;
            }

            for (size_t i = 0;i < arraytmp.size(); ++beg, ++i){
                *beg = arraytmp.at(i);
            }
        }
    }

	template <typename ForwardIterator, typename Pred = std::less<typename ForwardIterator::value_type>>
	void merge_sort(ForwardIterator beg, ForwardIterator end, Pred pred = std::less<typename ForwardIterator::value_type>())
	{
        const size_t size = std::distance(beg, end);
        if (size < 2){
            return;
        }

        ForwardIterator mid = beg + (size * 0.5);
        merge_sort(beg, mid, pred);
        merge_sort(mid, end, pred);
        __internal::merge(beg, mid, end, pred);
	}
}



#endif // _h_mergesort_included