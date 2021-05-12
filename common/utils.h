#ifndef _i_utils_included
#define _i_utils_included
#include <iterator>
#include <iostream>


namespace utils
{
	template <class ForwardIterator>
	void print_container(ForwardIterator beg, ForwardIterator end)
	{
		std::copy(beg, end, std::ostream_iterator<typename ForwardIterator::value_type>(std::clog, " "));
		std::clog << "\n";
	}
}


#endif // _i_utils_included
