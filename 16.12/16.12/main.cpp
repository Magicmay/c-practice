#include <iostream>

template <typename T>
typename T::value_type mostFre(T first, T last)
{
	//用于分配内存的对象
	//只适用于vector,方法1
/*	allocator<typename T::value_type> alloc;
	T newFirst = alloc.allocate(last - first);
	T newLast = newFirst + (last - first);*/

	//适用于vecotr、list、deque,方法2
	std::size_t amount = 0;
	T start = first;
	while (start!=last)
	{
		amount++;
		start++;
	}
	typedef std::vector<typename T::value_type> vecType;
	vecType vec(amount);
	vecType::iterator newFirst = vec.begin();
	vecType::iterator newLast = vec.end();

	std::uninitialized_copy(first, last, newFirst);
	std::sort(newFirst, newLast);
	std::size_t maxOccu = 0, occu = 0;
	T preIter = newFirst, maxOccuElemIt = newFirst;
	while (newFirst != newLast)
	{
		if (*newFirst!=*preIter)
		{
			if (occu>maxOccu)
			{
				maxOccu = occu;
				maxOccuElemIt = preIter;
			}
			occu = 0;
		}
		++occu;
		preIter = newFirst;
		++newFirst;
	}
	if (occu>maxOccu)
	{
		maxOccu = occu;
		maxOccuElemIt = preIter;
	}
	return *maxOccuElemIt;
}