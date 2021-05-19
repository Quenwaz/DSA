#ifndef __quick_sort_included_
#define __quick_sort_included_
#include <algorithm>


namespace sort
{
	namespace  __internal
	{
		template <typename ForwardIterator>
		ForwardIterator __quick_sort(ForwardIterator beg, ForwardIterator end)
		{
			if (std::distance(beg, end) < 2)
			{
				return beg;
			}
			
			ForwardIterator pivot = beg;
			for (ForwardIterator pos = beg; pos != end; ++pos)
			{
				if (*pivot > *pos)
				{
					if (std::distance(pivot, pos) > 1)
					{
						std::rotate(pivot, pos, pos + 1);
						++pivot;
					}
					else
					{
						std::iter_swap(pos, pivot);
						pivot = pos;
					}
				}

			}
			return pivot;
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