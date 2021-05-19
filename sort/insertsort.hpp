#ifndef _insert_sort_h_
#define _insert_sort_h_
#include <functional>

namespace sort
{
	template <typename ForwardIterator, typename Pred = std::less<typename ForwardIterator::value_type>>
	void insert_sort(ForwardIterator beg, ForwardIterator end, Pred pred = std::less<typename ForwardIterator::value_type>())
	{
		if (std::distance(beg, end) < 2)
		{
			return;
		}

		for (ForwardIterator pos = beg + 1; pos != end; ++pos)
		{
			for (ForwardIterator i =beg; i != pos; ++i)
			{
				if (pred(*pos, *i))
				{
					std::iter_swap(pos, i);
				}
			}
		}

	}
}

#endif // _insert_sort_h_

