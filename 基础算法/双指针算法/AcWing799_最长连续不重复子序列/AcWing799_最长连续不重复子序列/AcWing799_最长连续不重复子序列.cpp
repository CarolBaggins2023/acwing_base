#include <array>
#include <iostream>
#include <vector>

class Solution {
public:
    int GetLen(const std::vector<int> &nums) {
        // dp[i]是以nums[i]结尾的连续子串的最长不重复区间长度
        // dp[i] = dp[i - 1] + 1 if cnt[i] == 0 else --cnt[j], ++j
        int max_len = 1;
        std::vector<int> dp(nums.size(), 1);
        std::array<int, static_cast<int>(1e5 + 1)> cnt{};
        ++cnt[nums[0]];
        for (int i = 0, j = 1; j < nums.size(); ++j) {
            ++cnt[nums[j]];
            while (i < j && cnt[nums[j]] > 1) {
                --cnt[nums[i]];
                ++i;
            }
            max_len = std::max(max_len, j - i + 1);
        }
        return max_len;
    }
};

int main(int argc, char* argv[])
{
    int n = 0;
    std::vector<int> nums;
    scanf_s("%d", &n);
    for (int i = 0; i < n; ++i) {
        int num = 0;
        scanf_s("%d", &num);
        nums.emplace_back(num);
    }

    Solution sol;
    printf("%d", sol.GetLen(nums));
    
    return 0;
}
