#include <iostream>
#include <deque>
#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> nextGreaterElements_TwoPoints(std::vector<int>& nums) {
        std::vector<int> res(nums.size(), -1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < 2 * nums.size(); ++j) {
                int k = j % nums.size();
                
                if (k == i) {
                    break;
                }

                if (nums[k] > nums[i]) {
                    res[i] = nums[k];
                    break;
                }
            }
        }

        return res;
    }

    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        std::vector<int> res(nums.size(), -1);
        std::stack<int, std::deque<int>> stk;
        stk.push(nums.back());
        for (int i = 2 * nums.size() - 2; i >= 0; --i) {
            int j = i % nums.size();
            while (!stk.empty() && stk.top() <= nums[j]) {
                stk.pop();
            }
            res[j] = stk.empty() ? -1 : stk.top();
            stk.push(nums[j]);
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums{1,2,3,4,3};
    Solution sol;
    std::vector<int> res = sol.nextGreaterElements(nums);
    for (int i : res) {
        std::cout << i << " ";
    }
    
    return 0;
}
