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


//#include <iostream>
//#include <vector>
//#include <cstdlib>
//using namespace std;
//int func(vector<int>& vec)
//{
//	int ans = 0;
//	int n = vec.size();
//	for (int i = 0; i < n - 2; ++i)
//	{
//		if (vec[i] == 0)
//		{
//			vec[i] ^= 1;
//			vec[i + 1] ^= 1;
//			vec[i + 2] ^= 1;
//			++ans;
//		}
//	}
//	if (vec[n - 1] == 0 || vec[n - 2] == 0)
//	{
//		return -1;
//	}
//	return ans;
//}
//int main()
//{
//	vector<int> vec = { 0,1,1,1 }; // 1 0 0 0 0...1 1 1 1 0
//	cout << func(vec);
//
//	return 0;
//}



//int func(vector<int>& vec)
//{
//	int ans = 0;
//	for (auto& x : vec)
//	{
//		// if (x == 0 && 0 == ans % 2) // ans % 2 , 若ans为偶数, 则取模之后为0, 否则为1, 偶数次则不进行操作
//		// 简化之后就是 值为0, 且为偶数次操作时(偶数等于没操作, 当成是第一次操作)
//		// 这是第一种, 另一种是:
//		// 当x为1时, 且ans % 2为1(奇数)时, 此时为需要变化的情况, 说明是奇次的变化使得原先的1变成了0, 所以需要进行变化
//		// if(x == 1 && 1 == ans & 2)
//		if(x == ans % 2)
//		{
//			++ans;
//		}
//	}
//	return ans;
//}

//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words) 
//    {
//        vector<int> ans;
//        cout << "111";
//        return ans;
//    }
//};
// 
//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        vector<int> ans;
//        int sSize = s.size();
//        int size = words.size();
//        int n = words[0].size();
//        if (sSize < (size * n))
//        {
//            return {};
//        }
//        unordered_map<string, int> hash1, hash2;
//        for(auto & word : words)
//        {
//            hash1[word]++;
//        }
//        for(int k = 0; k < n; k++)
//        {
//            for(int left = 0, right = 0 + k, count = 0; right < sSize - k; right += n)
//            {
//                string tmp; 
//                int i = 0;
//                while(i < n && (right + i < sSize))// 截取单个单词长度的单词
//                {
//                    tmp += s[right + i++];
//                }
//                {
//                    ++hash2[tmp];
//                }
//                if (hash2[tmp] <= hash1[tmp])
//                {
//                    ++count;
//                    if (count == 1)
//                    {
//                        left = right;
//                    }
//                }
//                if((right - left + 1) > (size * n))
//                {
//                    int j = 0;
//                    string st;
//                    while(j < n && (left + j < sSize))
//                    {
//                        st += s[left + j++];
//                    } 
//                    left += n;
//
//                    if (hash2[st] <= hash1[st] && count != 0)
//                    {
//                        --count;
//                    }
//                    if (hash2[st] != 0)
//                    {
//                        --hash2[st];
//                    }
//                }
//                if (count == size)
//                {
//                    ans.push_back(left);
//                }
//            }
//            hash2.clear();
//        }
//        return ans;
//    }
//};
////vector<int> func()
////{
////    vector<int> vec;
////    cout << "11111";
////    return vec;
////}
//int main()
//{
//    string s = "b";
//    vector<string> vec = { "bbb","bbb"};
//    Solution obj;
//    vector<int> ans = obj.findSubstring(s, vec);
//    for (auto& e : ans)
//    {
//        cout << e << " ";
//    }
//     //vector<int> vec = { 0,1,1,0,1 };
//     //func();
//     //printf("%d", 3);
//
//
//
//	return 0;
//}


//int main()
//{
//	vector<char> vec = { 'a', 'b', 'c', 'a', 'd', 'f'};
//	unordered_map<char, int> map1;
//	for (auto& e : vec)
//	{
//		if (map1[e] != 0)
//		{
//			map1[e]--;
//			cout << map1.size() << endl;
//		}
//		map1[e]++;
//
//	}
//
//
//
//
//	return 0;
//}

//
//
//int main()
//{
//	vector<int> month = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	int w = 6;// 这一年的第一天为周六
//	int ans = 0;
//	for (int i = 0; i < 12; ++i)
//	{
//		for (int j = 1; j <= month[i]; ++j)
//		{
//			if (w == 6 || w == 0 || j == 1 || j == 11 || j == 21 || j == 31)
//			{
//				++ans;
//			}
//			w = (w + 1) % 7;// 该天结束之后, 也要对周几进行++, 不能超过7, 所以进行取模
//		}
//	}
//	cout << ans;
//
//
//
//
//
//	return 0;
//}


//// 高精度
//int main()
//{
//	string s1((size_t)100000, 0);// 输入只能选择使用字符数组, 数字数组不行
//	string s2((size_t)100000, 0);// 输入只能选择使用字符数组, 数字数组不行
//	vector<int> num1((size_t)100000, 0);
//	vector<int> num2((size_t)100000, 0);
//	vector<int> num3((size_t)100000, 0);// 存放结果
//	cin >> s1;
//	cin >> s2;
//	int len1 = s1.size();// 计算位数
//	int len2 = s2.size();
//	for (int i = 0; i < len1; ++i)// 按照习惯, 我们是高位在下标小的位置, 所以在进行字符转数字的时候, 也进行翻转
//	{
//		num1[i] = s1[len1 - 1 - i] - '0';
//	}
//	for (int i = 0; i < len2; ++i)
//	{
//		num2[i] = s2[len2 - 1 - i] - '0';
//	}
//	// cout << num1.size();
//	//for (auto& e : num1) // 打印时需要注意, 要使用字符长度的大小作为上界, 如果使用数组长度作为上界, 因为vector实现size和string实现的size不同, 要当实际容量作为使用, 可以使用string的
//	//{
//	//	cout << e << " ";
//	//}
//
//	//num1.resize(len1);// 调整大小, 以便使用(虽然这边可能用不到)
//	//num2.resize(len2);
//	// 调整完大小之后, 还要注意
//
//	int len = len1 > len2 ? len1 : len2;
//	int tmp = 0;
//	for (int i = 0; i < len; ++i)// 逆序存储的还有一个好处就是进位可以放在后面
//	{
//		num3[i] = num1[i] + num2[i] + tmp;
//		/*if (num3[i] > 9)
//		{
//			tmp = num3[i] / 10;
//			num3[i] %= 10;
//		}*/
//		tmp = num3[i] / 10;// 可以不需要这个if, 因为不管如何都不影响结果
//		num3[i] %= 10;// 已经存好进位, 所以只需要把当前值取模放入当前为即可
//	}
//	if (tmp > 0)
//	{
//		num3[len++] = tmp;
//	}
//	for (int i = len - 1; i >= 0; --i)
//	{
//		cout << num3[i];
//	}
//
//	return 0;
//}
//

//// 优化版本
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	size_t len = max(s1.size(), s2.size());
//	vector<int> num1(len, 0), num2(len, 0);// 适合两个数据源大小差不多大的情况, 若存在一方数据源过大, 就会造成内存浪费
//	transform(s1.rbegin(), s1.rend(), num1.begin(), [](const char& c) {return c - '0'; });
//	transform(s2.rbegin(), s2.rend(), num2.begin(), [](const char& c) {return c - '0'; });
//	
//	int carry = 0;
//	for (int i = 0; i < len; ++i)
//	{
//		num1[i] = num1[i] + num2[i] + carry;
//		carry = num1[i] / 10;
//		num1[i] %= 10;
//	}
//	if (carry > 0)
//	{
//		num1.push_back(carry);
//	}
//	for (auto it = num1.rbegin(); it < num1.rend(); ++it)
//	{
//		cout << *it;
//	}
//	return 0;
//}


//
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	size_t len = max(s1.size(), s2.size());// 长度
//	vector<int> num1(len, 0), num2(len, 0);// 
//	transform(s1.rbegin(), s1.rend(), num1.rbegin(), [](const char& c) {return c - '0'; });// 默认第一个为减数
//	transform(s2.rbegin(), s2.rend(), num2.rbegin(), [](const char& c) {return c - '0'; });// 第二个为被减数
//
//	int carry = 0;
//	for (int i = 0; i < len; ++i)
//	{
//		if (num1[i] > num2[i])
//		{
//			num 
//		}
//	}
//
//
//
//	return 0;
//}

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <functional>
#include <bitset>
//using namespace std;
//class Solution {
//public:
//    bool exist(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j, string& s, int k)
//    {
//        if (grid[i][j] != s[k]) {
//            return false;
//        } else if (k == s.length() - 1) // 到了当前元素, 且一样, 就已经能表明是出口, 直接返回结果. 递归出口处就已经表明, 只有到了结果处才会返回, 所以一直递归进最深处, 
//        {
//            return true;
//        }
//        visited[i][j] = true;// 当前元素已遍历, 进行更改 
//        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};// 方向
//        bool result = false;// 用于返回结果
//        for (const auto& dir : directions)// 遍历四个方向
//        {
//            int newi = i + dir.first;
//            int newj = j + dir.second;
//            if (newi >= 0 && newi <= grid.size() && newj >= 0 && newj <= grid[0].size())// 保证方向不越界
//            {
//                if (visited[newi][newj] == false)// 且若当前节点未进行遍历, 则进行处理
//                {
//                    bool flag = exist(grid, visited, i, j, s, k + 1);
//                    if (flag)// 在回溯时, 结果有两种, 当得到为真的返回值, 意味着已到达终点处, 到了结果该记录的位置, 进行记录, 然后跳出循环, 进行当前回溯的返回
//                    {
//                        result = true;
//                        break;
//                    }
//                }
//            }
//        }
//        visited[i][j] = false;// 四个方向遍历结束之后未找到满足的target的值(有可能是还未到该下标对应的访问时间, 就已经进行了访问, 所以进行复原), 则将这个已访问的节点改为未访问, 表示需从其他路径来对该节点进行遍历
//        return result;
//    }
//    bool wordPuzzle(vector<vector<char>>& grid, string target) {
//        int h = grid.size(), w = grid[0].size();
//        vector<vector<int>> visited(h, vector<int>(w));// 用于存放已遍历过的元素
//        for (int i = 0; i < h; i++)// 遍历每个元素
//        {
//            for (int j = 0; j < w; j++)
//            {
//                bool flag = exist(grid, visited, i, j, target, 0);// 看这个迷宫内的元素是否满足题意
//                if (flag) {
//                    return true;
//                }
//            }
//        }
//
//    }
//};
//
//int main()
//{
//    vector<vector<char>> grid = { 
//        {'A', 'B', 'C', 'E'},
//        {'S', 'F', 'C', 'S'},
//        {'A', 'D', 'E', 'E'}
//    };
//    string target = "ABCCED";
//    Solution s;
//    s.wordPuzzle(grid, target);
//
//
//
//
//    return 0;
//}

using namespace std;
//int gcd(int a, int b)
//{
//	while (b != 0)
//	{
//		int t = a % b;
//		a = b;
//		b = t;
//	}
//	return a;
//}
//
//// 这段代码还可以使用
//int gcd(int a, int b)
//{
//	return b == 0 ? a : gcd(b, a % b);
//}
//int main()
//{
//	int num = 0;
//	for (int i = 1; i <= 2020; ++i)
//	{
//		if (gcd(i, 1018) == 1)
//		{
//			++num;
//		}
//	}
//	cout << num;
//
//
//
//
//
//}

//
//
//int  main()
//{
//
//	// 方法1, 回溯暴搜
//	//int n = 0;
//	//cin >> n;
//	//vector<string> ans;
//	//string str;
//
//	//function<void(string&)> dfs = [&](string& str)
//	//	{
//	//		if (str.size() == n)
//	//		{
//	//			ans.push_back(str);
//	//			return;
//	//		}
//	//		if (str.empty() || str.back() == '1')
//	//		{
//	//			str.push_back('0');
//	//			dfs(str);
//	//			str.pop_back();
//	//		}
//	//		str.push_back('1');
//	//		dfs(str);
//	//		str.pop_back();
//	//	};
//	//dfs(str);
//	//for (auto& s : ans)
//	//{
//	//	cout << s << endl;
//	//}
//
//	// 方法2
//	// 位运算
//	vector<string> ans;
//	int n = 0;
//	cin >> n;
//	int mask = (1 << n) - 1;// 构造全1的n位二进制数
//	int x = 1 << n;// 表示2^n
//	for (int i = 0; i < x; ++i)// 在0 ~~ x-1 中筛选
//	{
//		if (((i >> 1) & i) == 0)// 当前值与右移一位的值进行与运算，如果结果为0，则说明当前值没有连续的1交替出现，符合要求
//		{
//			ans.push_back(bitset<18>(i ^ mask).to_string().substr(18 - n));//取反得到原先的二进制表示，再取子串
//		}
//	}
//	for (auto& x : ans)
//	{
//		cout << x << endl;
//	}
//	
//}
//
//// 
//


//
//
//int main()
//{
//	string s = "001";
//	int i = 0;
//	for (auto& x : s)
//	{
//		if ((x - '0') != 0)
//		{
//			break;
//		}
//		++i;
//	}
//	int flag = 0;
//	if (((s[i] - '0') & 1) != 0)// 为奇数
//	{
//		flag = 1;
//	}
//	for(; i < s.size(); ++i)
//	{
//		if (((s[i] - '0') & 1) == 0 && flag == 1)// 是偶数
//		{
//			flag = 0;
//		}
//		else if(flag == 0)
//		{
//			flag = 1;
//		}
//		else
//		{
//			swap(s[i], s[i - 1]);
//		}
//	}
//}
//
////上述不如题解思路
//{
//	class Solution {
//	public:
//		string getSmallestString(string s) {
//			// 按照题意 最多交换一次, 可以交换次数为0 或者1
//			// 要得到最小字典序, 所以交换的值越左边越好
//			// 得到最小, 所以交换后的值一定比原先的值严格小于, 所以一定是左边大于右边
//			for(int i = 1; i < s.size(); ++i)
//			{
//				if(s[i - 1] > s[i] && s[i - 1] % 2 == s[i] % 2)// 字符串对应的数字奇偶性, 就是ascii的奇偶性
//				{
//					swap(s[i], s[i - 1]);
//					break;
//				}
//			}
//			return s;
//		}
//	};
//}

//
//class Solution {
//public:
//    vector<int> resultsArray(vector<int>& nums, int k) {
//        int n = nums.size();
//        vector<int> ans;
//        int left = 0, right = 0;
//        if (k == 1) return nums;
//        while(left <= n - k)
//        {
//            int right_val = nums[right++];//1,2,3,4,3,2,5
//            if(right - left + 1 == k)
//            {
//                int ltmp = left;
//                int rtmp = right;
//                for(;ltmp < rtmp;++ltmp)
//                {
//                    if (nums[ltmp] > nums[ltmp + 1])
//                    {
//                        ans.push_back(-1);
//                        break;
//                    }
//                }
//                if (ltmp == rtmp && nums[rtmp - 1] < nums[rtmp])
//                {
//                    ans.push_back(nums[rtmp]);
//                }
//
//                ++left;
//                right = left;
//            }
//           
//        }
//        return ans;
//    }
//};
//
//int main()
//{
//
//	vector<int> nums = { 1,2,3,4,3,2,5};
//	int k = 3;
//	Solution s;
//	auto ans = s.resultsArray(nums, k);
//	for (auto& x : ans)
//	{
//		cout << x << endl;
//	}
//}

//
//
//class NeighborSum {
//    vector<vector<int>> _grid;
//    vector<vector<int>> Ad_next = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
//    vector<vector<int>> Di_next = {{-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
//
//public:
//    NeighborSum(vector<vector<int>>& grid) : _grid(grid) {}
//
//    int adjacentSum(int value) {
//        int ans = 0;
//        pair<int, int> p = FindPos(value);
//        int x = p.first;
//        int y = p.second;
//        for (int i = 0; i < 4; ++i) {
//            if (x > 0 && Ad_next[i][0] == -1) {
//                ans += _grid[x + Ad_next[i][0]][y];
//            }
//            if (x < 0 && Ad_next[i][0] == 1)
//            {
//                ans += _grid[x + Ad_next[i][0]][y];
//            }
//            if(y > 0 && Ad_next[i][1] == -1)
//            {
//                ans += _grid[x][y + Ad_next[i][1]];
//            }
//            if(y < 0 && Ad_next[i][1] == 1)
//            {
//                ans += _grid[x][y + Ad_next[i][1]];
//            }
//        }
//        return ans;
//    }
//
//    int diagonalSum(int value) {
//        int ans = 0;
//        pair<int, int> p = FindPos(value);
//        int x = p.first;
//        int y = p.second;
//        return ans;
//    }
//    pair<int, int> FindPos(int value) {
//        for (int i = 0; i < _grid.size(); ++i) {
//            for (int j = 0; j < _grid[0].size(); ++j) {
//                if (value == _grid[i][j]) {
//                    return {i, j};
//                }
//            }
//        }
//        return {};
//    }
//};
//
////int main()
////{
////    vector<vector<int>> vec = { { 0,1,2 }, { 3,4,5 }, { 6,7,8 } };
////    NeighborSum s(vec);
////    cout << s.adjacentSum(1) << endl;
////    cout << s.adjacentSum(4) << endl ;
////}
///**
//* Your NeighborSum object will be instantiated and called as such:
//* NeighborSum* obj = new NeighborSum(grid);
//* int param_1 = obj->adjacentSum(value);
//* int param_2 = obj->diagonalSum(value);
//*/
//
//class Solution {
//public:
//    int countKConstraintSubstrings(string s, int k) {
//        int left = 0, right = 0;
//        int res = 0;
//        int n = s.size();
//        int cnt[2] = {0};
//
//        while (right < n) {
//            ++cnt[s[right++] - '0'];
//
//            while ((cnt[0] > k) && (cnt[1] > k)) {
//                --cnt[s[left++] - '0'];
//            }
//
//            res += right - left;
//        }
//
//        return res;
//    }
//};
//
//int main() {
//    Solution sol;
//
//    return 0;
//}


//int func()
//{
//	int x = 1;
//	return x;
//}
//int main()
//{
//	int x = func();
//	cout << x << endl;
//
//	return 0;
//}
//
//class MyStack {
//public:
//	MyStack(int k) {
//		_capacity = k;
//	}
//	// 进栈
//	bool Push(int x)
//	{
//		if (isFull())
//		{
//			return false;
//		}
//		if (q1.empty())
//		{
//			q2.push(x);
//		}
//		else
//		{
//			q1.push(x);
//		}
//		++_capacity;
//		return true;
//	}
//	// 出栈
//	// 获取栈顶元素
//	int Front()
//	{
//
//	}
//	// 判空
//	bool isEmpty()
//	{
//		return _capacity == 0;
//	}
//	// 判满
//	bool isFull()
//	{
//		return q1.size() == _capacity || q2.size() == _capacity;
//	}
//	MyStack() {}
//private:
//	queue<int> q1;
//	queue<int> q2;
//	int _capacity;
//};
//
//int main()
//{
//	MyStack s1;
//	s1.Push(1);
//
//	return 0;
//}

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        int n = ages.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double x = ages[i];
                double y = ages[j];
                if (y <= 0.5 * x + 7 || y > x || y > 100 && x < 100) {
                    ++ans;
                } 
                else {
                    swap(x, y);
                    if (y <= 0.5 * x + 7 || y > x || y > 100 && x < 100) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> vec = { 16, 16 };
    int n = s.numFriendRequests(vec);
    cout << n;
    return 0;
}