#include <deque>
#include <iostream>
#include <stack>
#include <vector>

// 单调栈的思想在于，在二重循环（双指针，暴力解法）的基础上，去除第二重循环中不可能作为答案的元素
// 栈中保存的元素，就是第二重循环中需要考虑的值
// 因为这些值自然地形成递增或递减（按照需求，在需求的评价指标上），所以称为单调栈

std::vector<int> GetRes(const std::vector<int> &nums) {
    std::stack<int, std::deque<int>> stk;
    std::vector<int> res;
    stk.push(0);
    res.emplace_back(-1);
    for (int i = 1; i < nums.size(); ++i) {
        // 去除第二重循环中不可能作为答案的元素
        while (!stk.empty() && nums[i] <= nums[stk.top()]) {
            stk.pop();
        }
        res.emplace_back(stk.empty() ? -1 : nums[stk.top()]);
        stk.push(i);
    }

    return res;
}

int main(int argc, char* argv[])
{
    int N = 0;
    std::vector<int> nums;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int x = 0;
        std::cin >> x;
        nums.emplace_back(x);
    }

    std::vector<int> res = GetRes(nums);
    for (int i : res) {
        std::cout << i << " ";
    }
    
    return 0;
}
