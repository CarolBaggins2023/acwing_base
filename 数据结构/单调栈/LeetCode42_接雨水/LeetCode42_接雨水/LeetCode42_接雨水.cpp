#include <deque>
#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    int trap_refer(std::vector<int>& height) {
        int res = 0;
        std::stack<int, std::deque<int>> stk;
        stk.push(0);
        for (int i = 1; i < height.size(); ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int mid = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    int left = stk.top();
                    int right = i;
                    res += (std::min(height[left], height[right]) - height[mid]) * (right - left - 1);
                }
            }
            stk.push(i);
        }

        return res;
    }

    int trap1(std::vector<int>& height) {
        std::vector<int> left_idx(height.size());
        for (int i = 0; i < height.size(); ++i) {
            int tmp = i - 1;
            while (tmp >= 0 && height[tmp] <= height[i]) {
                --tmp;
            }
            left_idx[i] = tmp;
        }
        
        std::vector<int> right_idx(height.size());
        for (int i = 0; i < height.size(); ++i) {
            int tmp = i + 1;
            // 注意，while的判断中，不再是 <=，而是 <
            // 因为如果对两侧的判断是相同的，那么以height={0,1,0,2,1,0,1,3,2,1,2,1}为例，会出现面积重复计算
            while (tmp < height.size() && height[tmp] < height[i]) {
                ++tmp;
            }
            right_idx[i] = tmp;
        }

        int sum = 0;
        for (int i = 0; i < height.size(); ++i) {
            int part_sum = 0;
            if (left_idx[i] != -1 && right_idx[i] != height.size()) {
                part_sum = (right_idx[i] - left_idx[i] - 1) * (std::min(height[left_idx[i]], height[right_idx[i]]) - height[i]);
            }
            sum += part_sum;
        }

        return sum;
    }

    int trap2(std::vector<int>& height) {
        std::vector<int> left_idx(height.size());
        std::stack<int> stk_left;
        left_idx[0] = -1;
        stk_left.push(0);
        for (int i = 1; i < height.size(); ++i) {
            while (!stk_left.empty() && height[stk_left.top()] <= height[i]) {
                stk_left.pop();
            }
            left_idx[i] = stk_left.empty() ? -1 : stk_left.top();
            stk_left.push(i);
        }

        std::vector<int> right_idx(height.size());
        std::stack<int> stk_right;
        right_idx[height.size() - 1] = height.size();
        stk_right.push(height.size() - 1);
        for (int i = height.size() - 1; i >= 0; --i) {
            // 对while的判断条件有特殊处理，看trap1
            while (!stk_right.empty() && height[stk_right.top()] < height[i]) {
                stk_right.pop();
            }
            right_idx[i] = stk_right.empty() ? height.size() : stk_right.top();
            stk_right.push(i);
        }
        
        int sum = 0;
        for (int i = 0; i < height.size(); ++i) {
            int part_sum = 0;
            if (left_idx[i] != -1 && right_idx[i] != height.size()) {
                part_sum = (right_idx[i] - left_idx[i] - 1) * (std::min(height[left_idx[i]], height[right_idx[i]]) - height[i]);
            }
            sum += part_sum;
        }

        return sum;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> v{4,2,0,3,2,5};
    Solution solution;
    int res = solution.trap2(v);
    std::cout << res;
    
    return 0;
}
