#ifndef __quick_sort_included_
#define __quick_sort_included_
#include <algorithm>
#ifdef DEBUG
#include <iostream>
#include <iterator>
#endif
namespace dsa::alg::sort
{
	namespace  __internal
	{
		template <typename ForwardIterator>
		ForwardIterator __quick_sort(ForwardIterator beg, ForwardIterator end)
		{
			const auto size = std::distance(beg, end);
			if(size < 2 ){
				return beg;
			}
#ifdef DEBUG
			std::copy(beg, end, std::ostream_iterator<typename ForwardIterator::value_type>(std::clog, " "));
			std::clog << std::endl;
#endif
			ForwardIterator p = beg;
			ForwardIterator left = beg + 1;
			ForwardIterator right = beg + size -1;

			for(;left <= right;)
			{
				if (left <= right)
				{
					if ((*left) < (*p)){
						++left;
					}

					if ((*right) >= (*p)){
						--right;
					}
				}

				if (left < right){
					std::iter_swap(left, right);
				}
#ifdef DEBUG
				std::copy(beg, end, std::ostream_iterator<typename ForwardIterator::value_type>(std::clog, " "));
				std::clog << std::endl;
#endif
			}

			std::iter_swap(beg, right);
#ifdef DEBUG
			std::copy(beg, end, std::ostream_iterator<typename ForwardIterator::value_type>(std::clog, " "));
			std::clog << std::endl;
#endif
			return right;
		}
	}

	template <typename ForwardIterator>
	void quick_sort(ForwardIterator beg, ForwardIterator end)
	{
		if (std::distance(beg, end) < 2)
		{
			return;
		}

		ForwardIterator mid = __internal::__quick_sort(beg, end);
		quick_sort(beg, mid);
		quick_sort(mid + 1, end);
	}
}


#endif // __quick_sort_included_