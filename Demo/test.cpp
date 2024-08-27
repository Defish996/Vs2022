#include <iostream>
#include <vector>
#include <numeric>
int main()
{
	//  π”√iota
	std::vector<int> vec(10, 0);
	std::iota(vec.begin(), vec.end(), 1);
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	return 0;
}