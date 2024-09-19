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
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {// [1,0,7,2,4,3,1,0,2,6]//[1,0,2,3,0,4,5,0]// 1,2,3,4,0 // 8,4,5,0,0,0,0,7 // 
        int n = arr.size();
        int dest = -1, cur = 0;
        while (cur < n)
        {
            if (arr[cur] == 0)
            {
                dest += 2;
                if (dest >= n - 1)// ��0, �ոպû����ǳ���һλ
                {
                    break;
                }
                ++cur;
                continue;
            }
            dest++;
            if (dest == n - 1) break;// �ոպ�
            cur++;
        }// �����һ������ѭ����, �����������, 
         //����β��0, ��0�Ҹպ�, ��0���ǳ���һλ, 
         //����0, �ոպ�
        if (cur == dest + 1) return;
        if (dest == n)// β����0, �ҳ���1λ
        {
            dest--;
            arr[dest--] = 0;
            cur--;
        }
        while (cur >= 0)
        {
            if (arr[cur] == 0)
            {
                arr[dest] = arr[cur];
                arr[--dest] = arr[cur];
            }
            else
            {
                arr[dest] = arr[cur];
            }
            --dest;
            --cur;
        }

    }
};

int main()
{
    Solution solution;
    //vector<int> nums = {1,0,2,3,0,4,5,0};
    // vector<int> nums = { 8,4,5,0,0,0,0,7 };
     vector<int> nums = { 1,0,7,2,4,3,1,0,2,6 };
    for(auto& e : nums)
    {
        cout << e << " ";
    }
    cout << endl;
    solution.duplicateZeros(nums);
    for(auto& e : nums)
    {
        cout << e << " ";
    }


    return 0;
}