#include <deque>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>
#include <utility>
#include <vector>

class Solution {

public:

    Solution() : result(std::string{"12345678x"}) {}

    int FindX(const std::string &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 'x') {
                return i;
            }
        }
        return -1;
    }

    bool IsValid(int idx, int step, std::string &nums, std::unordered_set<std::string> &visited) {
        int new_idx = idx + step;
        if (new_idx < 0 || new_idx >= nums.size()) {
            return false;
        }
        if ((idx % 3 == 0) && step == -1 || (idx % 3 == 2) && step == 1) {
            return false;
        }
        
        std::swap(nums[idx], nums[new_idx]);
        if (visited.find(nums) != visited.end()) {
            return false;
        }

        visited.insert(nums);
        return true;
    }
    
    int BFS(const std::string &ori_nums) {
        std::queue<std::pair<std::string, int>> que;
        que.emplace(ori_nums, 0);
        std::unordered_set<std::string> visited;
        visited.insert(ori_nums);
        std::vector<int> steps{-3, 3, -1, 1};
        
        while (!que.empty()) {
            std::pair<std::string, int> nums_cnt = que.front();
            std::string nums = nums_cnt.first;
            int cnt = nums_cnt.second;
            que.pop();

            if (nums == result) {
                return cnt;
            }

            int x_idx = FindX(nums);
            for (int step : steps) {
                std::string new_nums = nums;
                if (!IsValid(x_idx, step, new_nums, visited)) {
                    continue;
                }
                que.emplace(new_nums, cnt + 1);
            }
        }

        return -1;
    }

    const std::string result;
};

int main(int argc, char* argv[])
{
    std::string nums;
    for (int i = 0; i < 9; ++i) {
        char c = '\0';
        std::cin >> c;
        nums.push_back(c);
    }

    Solution sol;
    std::cout << sol.BFS(nums);
    
    return 0;
}
