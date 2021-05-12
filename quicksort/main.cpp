#include <vector>
#include <algorithm>
#include "common/defs.h"


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


int main(int argc, char* argv[])
{
	std::vector<int> vecTest = {9, 0, 5, 1, 2, 3, 8, 41, 32, 113, 4, 8};
	std::vector<int> vecTest1 = {5, 4, 3, 2, 1};
	sort::quick_sort(vecTest.begin(), vecTest.end());
	sort::quick_sort(vecTest1.begin(), vecTest1.end());
	TEST(vecTest == std::vector<int>({0, 1, 2, 3, 4, 5, 8, 8, 9, 32, 41, 113}));
	TEST(vecTest != std::vector<int>({ 1, 1, 2, 3, 4, 5, 8, 8, 9, 32, 41, 113 }));
	TEST(vecTest1 == std::vector<int>({ 1, 2, 3, 4, 5 }));

	getchar();
	return 0;
}
