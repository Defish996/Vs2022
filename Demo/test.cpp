#include <iostream>
#include <vector>
#include <string>
#include <numeric>

void dfs(const std::vector<int>& nums, std::vector<std::vector<int>>& ret, std::vector<int>& path, bool* check)
{
	if (nums.size() == path.size())
	{
		ret.push_back(path);
		return;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (check[i] == false)
		{
			check[i] = true;
			path.push_back(nums[i]);
			dfs(nums, ret, path, check);
			check[i] = false;
			path.pop_back();
		}
	}
}
std::vector<std::vector<int>> Full_permutation(int num)
{
	std::vector<int> nums(num);
	std::iota(nums.begin(), nums.end(), 1);
	std::vector<std::vector<int>> ret;
	std::vector<int> path;
	bool check[9] = {false};

	dfs(nums, ret, path, check);
	return ret;
}

int main()
{
	int a, b;
	std::cin >> a >> b;
	std::string s = std::to_string(b);
	std::vector<int> nums;
	for (auto& e : s)
	{
		nums.push_back(e - '0');
	}
	std::vector<std::vector<int>> ret = Full_permutation(a);
	for (int i = 0; i < ret.size(); i++)
	{
		if (ret[i] == nums)
		{
			std::cout << i + 1 << std::endl;
		}
	}
	return 0;
}