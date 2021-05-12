#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include "common/defs.h"
#include <vector>

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




int main(int argc, char* argv[])
{
	std::vector<int> vecTest = { 9, 0, 5, 1, 2, 3, 8, 41, 32, 113, 4, 8 };
	std::vector<int> vecTest1 = { 5, 4, 3, 2, 1 };
	sort::insert_sort(vecTest.begin(), vecTest.end());
	sort::insert_sort(vecTest1.begin(), vecTest1.end());
	TEST(vecTest == std::vector<int>({ 0, 1, 2, 3, 4, 5, 8, 8, 9, 32, 41, 113 }));
	TEST(vecTest != std::vector<int>({ 1, 1, 2, 3, 4, 5, 8, 8, 9, 32, 41, 113 }));
	TEST(vecTest1 == std::vector<int>({ 1, 2, 3, 4, 5 }));

	getchar();
	return 0;
}
