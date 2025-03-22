#include "Iter.hpp"

int	main(void)
{
	std::string arr[4] = 
		{"1", 
		"2", 
		"3", 
		"4"};

	::iter(arr, 4, foo);
	return (0);
}