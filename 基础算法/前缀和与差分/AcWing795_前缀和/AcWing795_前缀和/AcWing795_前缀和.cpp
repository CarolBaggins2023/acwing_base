#include <iostream>
#include <vector>

class Solution {
public:
    Solution(const std::vector<int> &nums) : Sum(std::vector<int>(1, 0)) {
        int sum = 0;
        for (const int num : nums) {
            sum += num;
            Sum.emplace_back(sum);
        }
    }
    
    int CalSum(int l, int r) {
        return Sum[r] - Sum[l - 1];
    }

    std::vector<int> Sum;
};

int main(int argc, char* argv[])
{
    int n, m;
    scanf_s("%d %d", &n, &m);

    std::vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf_s("%d", &num);
        nums.emplace_back(num);
    }

    Solution sol(nums);
    int l = 0, r = 0;
    for (int i = 0 ; i < m; ++i) {
        scanf_s("%d %d", &l, &r);
        std::printf("%d\n", sol.CalSum(l, r));
    }
    
    return 0;
}
