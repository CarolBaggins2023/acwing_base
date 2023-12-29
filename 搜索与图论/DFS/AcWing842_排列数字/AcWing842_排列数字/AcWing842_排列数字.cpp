#include <iostream>
#include <vector>

class Solution {

public:

    void BackTracking(const std::vector<int> &nums, std::vector<int> &used, std::vector<int> &path) {
        if (path.size() == nums.size()) {
            for (int i : path) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            path.emplace_back(nums[i]);
            BackTracking(nums, used, path);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;

    std::vector<int> nums;
    for (int i = 1; i <= n; ++i) {
        nums.emplace_back(i);
    }

    Solution sol;
    std::vector<int> used(nums.size(), false), path;
    sol.BackTracking(nums, used, path);
    
    return 0;
}
