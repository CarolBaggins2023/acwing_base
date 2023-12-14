#include <deque>
#include <iostream>
#include <stack>
#include <vector>

class Solution {
public:
    int largestRectangleArea1(std::vector<int>& heights) {
        std::vector<std::vector<int>> height_min(heights.size(), std::vector<int>(heights.size(), int_max));
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = i; j < heights.size(); ++j) {
                for (int k = i; k <= j; ++k) {
                    height_min[i][j] = std::min(height_min[i][j], heights[k]);
                }
            }
        }

        int area_max = 0;
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = i; j< heights.size(); ++j) {
                area_max = std::max(area_max, (j - i + 1) * height_min[i][j]);
            }
        }
        return area_max;
    }

    int largestRectangleArea2(std::vector<int>& heights) {
        int sum = 0;
        for (int i = 0; i < heights.size(); i++) {
            int left = i;
            int right = i;
            for (; left >= 0; left--) {
                if (heights[left] < heights[i]) break;
            }
            for (; right < heights.size(); right++) {
                if (heights[right] < heights[i]) break;
            }
            int w = right - left - 1;
            int h = heights[i];
            sum = std::max(sum, w * h);
        }
        return sum;
    }

    int largestRectangleArea3(std::vector<int>& heights) {
        std::vector<int> left_min_idx(heights.size(), -1);
        std::vector<int> right_min_idx(heights.size(), heights.size());
        for (int i = 0; i < heights.size(); ++i) {
            int min_idx = i - 1;
            while (min_idx >= 0 && heights[min_idx] >= heights[i]) {
                --min_idx;
            }
            left_min_idx[i] = min_idx;
        }
        for (int i = 0; i < heights.size(); ++i) {
            int min_idx = i + 1;
            while (min_idx < heights.size() && heights[min_idx] >= heights[i]) {
                ++min_idx;
            }
            right_min_idx[i] = min_idx;
        }

        int max_sum = 0;
        for (int i = 0; i < heights.size(); ++i) {
            max_sum = std::max(max_sum, heights[i] * (right_min_idx[i] - left_min_idx[i] - 1));
        }

        return max_sum;
    }

    int largestRectangleArea4(std::vector<int>& heights) {
        std::vector<int> left_min_idx(heights.size(), -1);
        std::stack<int, std::deque<int>> stk_left;
        stk_left.push(0);
        for (int i = 1; i < heights.size(); ++i) {
            while (!stk_left.empty() && heights[stk_left.top()] >= heights[i]) {
                stk_left.pop();
            }
            left_min_idx[i] = stk_left.empty() ? -1 : stk_left.top();
            stk_left.push(i);
        }

        std::vector<int> right_min_idx(heights.size(), heights.size());
        std::stack<int, std::deque<int>> stk_right;
        stk_right.push(heights.size() - 1);
        for (int i = heights.size() - 2; i >= 0; --i) {
            while (!stk_right.empty() && heights[stk_right.top()] >= heights[i]) {
                stk_right.pop();
            }
            right_min_idx[i] = stk_right.empty() ? heights.size() : stk_right.top();
            stk_right.push(i);
        }

        int max_sum = 0;
        for (int i = 0; i < heights.size(); ++i) {
            max_sum = std::max(max_sum, heights[i] * (right_min_idx[i] - left_min_idx[i] - 1));
        }

        return max_sum;
    }

    const int int_max = 0x3f3f3f3f;
};

int main(int argc, char* argv[])
{
    std::vector<int> heights{2,1,5,6,2,3};
    Solution solution;
    std::cout << solution.largestRectangleArea4(heights);
    
    return 0;
}
