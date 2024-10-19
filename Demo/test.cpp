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
//                // ������ǵ�һ��Ԫ�أ����Ҳ��������ĵ�һ��Ԫ��
//                if (j == 0 && i != 1) {
//                    // ����µĶ�������
//                    ans.push_back(to_string(nums[i]));
//                    j++;
//                } else if (ans[j - 1][ans[j - 1].size() - 1] - '0' + 1 == nums[i]) {
//                    // ����ǰһ����Χ�Ľ�������
//                    ans[j - 1] += "->" + to_string(nums[i - 1]);
//                    // ����µ���ʼ����
//                    ans.push_back(to_string(nums[i]));
//                    j++;
//                } else {
//                    // ����ǰһ����Χ�Ľ�������
//                    ans[j - 1] += "->" + to_string(nums[i - 1]);
//                    // ����µĶ�������
//                    ans.push_back(to_string(nums[i]));
//                    j++;
//                }
//            }
//        }
//
//        // �������һ����Χ
//        if (n > 0) {
//            if (j == 0) {
//                // ���ֻ��һ��Ԫ�أ����������һ��Ԫ��
//                ans.back() += "->" + to_string(nums[n - 1]);
//            } else {
//                // �������һ����Χ�Ľ�������
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
//    // ��������
//    std::vector<int> nums1 = {0, 1, 2, 4, 6, 7};
//    std::vector<int> nums2 = {0, 2, 3, 4, 6, 8, 9};
//    std::vector<int> nums3 = {1, 3, 5, 7, 9};
//    std::vector<int> nums4 = {};
//
//    // ���Բ���ӡ���
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
//                if (dest >= n - 1)// ��0, �ոպû����ǳ���һλ
//                {
//                    break;
//                }
//                ++cur;
//                continue;
//            }
//            dest++;
//            if (dest == n - 1) break;// �ոպ�
//            cur++;
//        }// �����һ������ѭ����, �����������, 
//         //����β��0, ��0�Ҹպ�, ��0���ǳ���һλ, 
//         //����0, �ոպ�
//        if (cur == dest + 1) return;
//        if (dest == n)// β����0, �ҳ���1λ
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
//    int total = 1000000; // �ܽ��
//    const int maxCountPerValue = 5; // ÿ�ֽ���������
//    const int base = 7; // ����ֵ
//
//    // �������п��ܵ�7����
//    std::vector<int> powers;
//    for (int power = 1; power <= total; power *= base) {
//        powers.push_back(power);
//    }
//
//    int count = 0; // �ֳɵ��ܷ���
//
//    // �Ӵ�С����ÿ��7����
//    for (auto it = powers.rbegin(); it != powers.rend(); ++it) {
//        int currentPower = *it;
//        // ��������䵱ǰ��������
//        for (int i = 0; i < maxCountPerValue && total >= currentPower; ++i, --total, ++count) {
//            // �����ܽ����Ӽ���
//        }
//    }
//
//    // ������
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
// // �ַ������ҵ��÷��ͽ�ȡ���÷�
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
//// ���ű�5.�������
//// �����������֮��*һ����λʱ���ڵ�ֵ, ����̫��, ˼������, �������, ��ȻҲ�ܳ���, ����Ч�ʲ���, �����߼�����, ���׳���
//// ˼��֮��ķ���������ȫ, ���Ǻõ�˼���ǽ�������һ���������֮�ϵ�, ����Ŀǰ�Ķ�������ǹؼ�  
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

//// 6. Ԫ����д 
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
