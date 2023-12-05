#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
    int MergeSections(std::vector<std::pair<int, int>> nums) {
        std::sort(nums.begin(), nums.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) -> bool {
            return a.first < b.first;
        });

        std::vector<std::pair<int, int>> res;
        res.emplace_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i].first > res.back().second) {
                res.emplace_back(nums[i]);
            } else {
                res.back().second = std::max(res.back().second, nums[i].second);
            }
        }
        return res.size();
    }
};

int main(int argc, char* argv[])
{
    int n = 0;
    std::vector<std::pair<int, int>> nums;
    scanf_s("%d", &n);
    for (int i = 0; i < n; ++i) {
        int l = 0, r = 0;
        scanf_s("%d %d", &l, &r);
        nums.emplace_back(l, r);
    }

    Solution solution;
    printf("%d", solution.MergeSections(nums));
    
    return 0;
}
