//#include <iostream>
//#include <vector>
//#include <string>
//#include <numeric>
//
//void dfs(const std::vector<int>& nums, std::vector<std::vector<int>>& ret, std::vector<int>& path, bool* check)
//{
//	if (nums.size() == path.size())
//	{
//		ret.push_back(path);
//		return;
//	}
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if (check[i] == false)
//		{
//			check[i] = true;
//			path.push_back(nums[i]);
//			dfs(nums, ret, path, check);
//			check[i] = false;
//			path.pop_back();
//		}
//	}
//}
//std::vector<std::vector<int>> Full_permutation(int num)
//{
//	std::vector<int> nums(num);
//	std::iota(nums.begin(), nums.end(), 1);
//	std::vector<std::vector<int>> ret;
//	std::vector<int> path;
//	bool check[9] = {false};
//
//	dfs(nums, ret, path, check);
//	return ret;
//}
//
//int main()
//{
//	int a, b;
//	std::cin >> a >> b;
//	std::string s = std::to_string(b);
//	std::vector<int> nums;
//	for (auto& e : s)
//	{
//		nums.push_back(e - '0');
//	}
//	//std::vector<int> nums(a);
//	//for (int i = 0; i < a; i++)
//	//{
//	//	nums[i] = s[i] - '0';
//	//}
//
//	std::vector<std::vector<int>> ret = Full_permutation(a);
//	for (int i = 0; i < ret.size(); i++)
//	{
//		if (ret[i] == nums)
//		{
//			std::cout << i + 1 << std::endl;
//		}
//	}
//	return 0;
//}


//using namespace std;
//class Solution {
//public:
//    vector<string> summaryRanges(vector<int>& nums) {
//        vector<string> ans;
//        int n = nums.size();
//
//        if (n == 0) return ans;
//
//        ans.push_back(to_string(nums[0]));
//        int j = 0;
//
//        for (int i = 1; i < n; i++) {
//            if (nums[i - 1] + 1 != nums[i]) {
//                // 如果这是第一个元素，并且不是连续的第一个元素
//                if (j == 0 && i != 1) {
//                    // 添加新的独立数字
//                    ans.push_back(to_string(nums[i]));
//                    j++;
//                } else if (ans[j - 1][ans[j - 1].size() - 1] - '0' + 1 == nums[i]) {
//                    // 更新前一个范围的结束部分
//                    ans[j - 1] += "->" + to_string(nums[i - 1]);
//                    // 添加新的起始部分
//                    ans.push_back(to_string(nums[i]));
//                    j++;
//                } else {
//                    // 更新前一个范围的结束部分
//                    ans[j - 1] += "->" + to_string(nums[i - 1]);
//                    // 添加新的独立数字
//                    ans.push_back(to_string(nums[i]));
//                    j++;
//                }
//            }
//        }
//
//        // 处理最后一个范围
//        if (n > 0) {
//            if (j == 0) {
//                // 如果只有一个元素，并且是最后一个元素
//                ans.back() += "->" + to_string(nums[n - 1]);
//            } else {
//                // 更新最后一个范围的结束部分
//                ans[j - 1] += "->" + to_string(nums[n - 1]);
//            }
//        }
//
//        return ans;
//    }
//};
//
//int main() {
//    Solution solution;
//
//    // 测试用例
//    std::vector<int> nums1 = {0, 1, 2, 4, 6, 7};
//    std::vector<int> nums2 = {0, 2, 3, 4, 6, 8, 9};
//    std::vector<int> nums3 = {1, 3, 5, 7, 9};
//    std::vector<int> nums4 = {};
//
//    // 测试并打印结果
//    std::vector<std::string> result1 = solution.summaryRanges(nums1);
//    std::cout << "Test Case 1: ";
//    for (const auto& s : result1) {
//        std::cout << "\"" << s << "\" ";
//    }
//    std::cout << std::endl;
//
//    std::vector<std::string> result2 = solution.summaryRanges(nums2);
//    std::cout << "Test Case 2: ";
//    for (const auto& s : result2) {
//        std::cout << "\"" << s << "\" ";
//    }
//    std::cout << std::endl;
//
//    std::vector<std::string> result3 = solution.summaryRanges(nums3);
//    std::cout << "Test Case 3: ";
//    for (const auto& s : result3) {
//        std::cout << "\"" << s << "\" ";
//    }
//    std::cout << std::endl;
//
//    std::vector<std::string> result4 = solution.summaryRanges(nums4);
//    std::cout << "Test Case 4: ";
//    for (const auto& s : result4) {
//        std::cout << "\"" << s << "\" ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr) {// [1,0,7,2,4,3,1,0,2,6]//[1,0,2,3,0,4,5,0]// 1,2,3,4,0 // 8,4,5,0,0,0,0,7 // 
//        int n = arr.size();
//        int dest = -1, cur = 0;
//        while (cur < n)
//        {
//            if (arr[cur] == 0)
//            {
//                dest += 2;
//                if (dest >= n - 1)// 是0, 刚刚好或者是超了一位
//                {
//                    break;
//                }
//                ++cur;
//                continue;
//            }
//            dest++;
//            if (dest == n - 1) break;// 刚刚好
//            cur++;
//        }// 找最后一个数的循环中, 存在三种情况, 
//         //数组尾是0, 是0且刚好, 是0但是超了一位, 
//         //不是0, 刚刚好
//        if (cur == dest + 1) return;
//        if (dest == n)// 尾数是0, 且超了1位
//        {
//            dest--;
//            arr[dest--] = 0;
//            cur--;
//        }
//        while (cur >= 0)
//        {
//            if (arr[cur] == 0)
//            {
//                arr[dest] = arr[cur];
//                arr[--dest] = arr[cur];
//            }
//            else
//            {
//                arr[dest] = arr[cur];
//            }
//            --dest;
//            --cur;
//        }
//
//    }
//};
//
//int main()
//{
//    //Solution solution;
//    ////vector<int> nums = {1,0,2,3,0,4,5,0};
//    //// vector<int> nums = { 8,4,5,0,0,0,0,7 };
//    // vector<int> nums = { 1,0,7,2,4,3,1,0,2,6 };
//    //for(auto& e : nums)
//    //{
//    //    cout << e << " ";
//    //}
//    //cout << endl;
//    //solution.duplicateZeros(nums);
//    //for(auto& e : nums)
//    //{
//    //    cout << e << " ";
//    //}
//
//
//    int x = 0;
//    int y = 1;
//    int z = -1;
//    if (y + z == -x)
//    {
//        cout << "true" << endl;
//    }
//
//
//
//
//
//
//
//
//
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//int main()
//{
//    int n = 1000000;
//    int count = 0;
//    while (n)
//    {
//        count += n % 7;
//        n /= 7;
//    }
//    std::printf("%d", count);
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//int main() {
//    int total = 1000000; // 总金额
//    const int maxCountPerValue = 5; // 每种金额的最大份数
//    const int base = 7; // 基础值
//
//    // 计算所有可能的7的幂
//    std::vector<int> powers;
//    for (int power = 1; power <= total; power *= base) {
//        powers.push_back(power);
//    }
//
//    int count = 0; // 分成的总份数
//
//    // 从大到小遍历每个7的幂
//    for (auto it = powers.rbegin(); it != powers.rend(); ++it) {
//        int currentPower = *it;
//        // 尽量多分配当前面额的数量
//        for (int i = 0; i < maxCountPerValue && total >= currentPower; ++i, --total, ++count) {
//            // 减少总金额并增加计数
//        }
//    }
//
//    // 输出结果
//    std::cout << count << std::endl;
//
//    return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
// // 字符串查找的用法和截取的用法
//	string s = "sda dsad dds";
//	const char BlankSpace = ' ';
//	int pos = s.size() - 1;
//	pos = s.rfind(BlankSpace, pos);
//	cout << pos-- << endl;
//	pos = s.rfind(BlankSpace, pos);
//	cout << pos;
//
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1	
//
//// 蓝桥杯5.充电能量
//// 问题就是秒数之差*一个单位时间内的值, 做题太少, 思考不够, 拿题就上, 虽然也能出来, 但是效率不高, 而且逻辑繁琐, 容易出错
//// 思考之后的方法才是万全, 但是好的思考是建立在右一定做题基础之上的, 所以目前的多做题才是关键  
//#include <iostream>
//#include <string>
//#include <cstdio>
//using namespace std;
//int main()
//{
//	struct Sum {
//		int UI = 0;
//		int Second = 0;
//	};
//	int n = 0, ans = 0;
//	cin >> n;
//
//	Sum sum[n];
//	int hour = 0, minute = 0, second = 0;
//	int U = 0, I = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		scanf("%d:%d:%d", &hour, &minute, &second);
//		cin >> U >> I;
//		sum[i].UI = U * I;
//		sum[i].Second = hour * 3600 + minute * 60 + second;
//	}
//	for (int i = 1; i < n; ++i)
//	{
//		ans += (sum[i].Second - sum[i - 1].Second) * sum[i - 1].UI;
//	}
//	cout << ans;
//
//
//	return 0;
//}


//#include <iostream>
//#include <cstdio>
//using namespace std;
//int main()
//{
//	char x = 'a';
//	printf("%d", x);
//
//
//	return 0;
//}

//// 6. 元音大写 
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    int hash[26] = { 0 };
//    hash['a' - 'a'] = 1;
//    hash['e' - 'a'] = 1;
//    hash['i' - 'a'] = 1;
//    hash['o' - 'a'] = 1;
//    hash['u' - 'a'] = 1;
//    string s;
//    cin >> s;
//    for(auto & e : s)
//    {
//        if(hash[e - 'a'] == 1)
//        {
//            e -= 32;
//        }
//    }
//    cout << s;
//    return 0;
//}


#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int func(vector<int>& vec)
{
	int ans = 0;
	int n = vec.size();
	for (int i = 0; i < n - 2; ++i)
	{
		if (vec[i] == 0)
		{
			vec[i] ^= 1;
			vec[i + 1] ^= 1;
			vec[i + 2] ^= 1;
			++ans;
		}
	}
	if (vec[n - 1] == 0 || vec[n - 2] == 0)
	{
		return -1;
	}
	return ans;
}
int main()
{
	vector<int> vec = { 0,1,1,1 }; // 1 0 0 0 0...1 1 1 1 0
	cout << func(vec);

	return 0;
}
