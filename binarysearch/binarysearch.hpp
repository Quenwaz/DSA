#ifndef _binary_search_included
#define _binary_search_included
#include <cstddef>


template<typename T>
int binary_search(T* array,size_t nLen, const T& target)
{
	if (nLen < 1) return -1;
	if (nLen == 1)
	{
		if (array[0] == target)
		{
			return 0;
		}

		return -1;
	}

	size_t _n_min = 0;
	size_t _n_max = nLen;
	size_t _n_middle = 0;
	do
	{
		_n_middle = _n_min + (_n_max - _n_min) / 2;
		T _middle = array[_n_middle];
		if (target > _middle)
		{
			_n_min = _n_middle + 1;
		}
		else if (target < _middle) {
			_n_max = _n_middle;
		}
		else
		{
			return _n_middle;
		}
	}
	while (_n_middle < nLen && _n_middle > 0);

	return -1;	
}


#endif // _binary_search_included