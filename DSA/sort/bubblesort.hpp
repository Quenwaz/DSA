#ifndef __bubble_sort_included
#define __bubble_sort_included
#include <functional>

namespace dsa::alg::sort
{
	template <typename ForwardIterator, typename Pred = std::less<typename ForwardIterator::value_type>>
	void bubble_sort(ForwardIterator beg, ForwardIterator end, Pred pred = std::less<typename ForwardIterator::value_type>())
	{
		if (std::distance(beg, end) < 2)
		{
			return;
		}

		for (ForwardIterator pos = beg; pos != end; ++pos)
		{
			for (ForwardIterator i = pos + 1; i != end; ++i)
			{
				if (!pred(*pos ,*i))
				{
					std::iter_swap(pos, i);
				}
			}
		}
		
	}
}



#endif // __bubble_sort_included