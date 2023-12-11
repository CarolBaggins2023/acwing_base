#include <deque>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> num2idx;
        for (int i = 0; i < nums1.size(); ++i) {
            num2idx.insert(std::make_pair(nums1[i], i));
        }

        std::stack<int, std::deque<int>> stk;
        std::vector<int> res(nums1.size(), -1);
        stk.push(nums2.size() - 1);
        for (int i = nums2.size() - 2; i >= 0; --i) {
            while (!stk.empty() && nums2[stk.top()] <= nums2[i]) {
                stk.pop();
            }
            if (num2idx.find(nums2[i]) != num2idx.end()) {
                res[num2idx[nums2[i]]] = stk.empty() ? -1 : nums2[stk.top()];
            }
            stk.push(i);
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums1{2, 4}, nums2{1, 2, 3, 4};
    Solution sol;
    std::vector<int> res = sol.nextGreaterElement(nums1, nums2);
    for (int i : res) {
        std::cout << i << " ";
    }
    
    return 0;
}
