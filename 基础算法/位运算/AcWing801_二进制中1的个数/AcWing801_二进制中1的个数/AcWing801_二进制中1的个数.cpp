#include <iostream>
#include <vector>

class Solution {
public:
    int CountOne(int x) {
        int cnt = 0;
        while (x > 0) {
            ++cnt;
            x -= (x & -x);
        }
        return cnt;
    }
    
    std::vector<int> GetRes(const std::vector<int> &nums) {
        std::vector<int> res;
        for (int num : nums) {
            res.emplace_back(CountOne(num));
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    int n = 0;
    std::vector<int> nums;
    scanf_s("%d", &n);
    for (int i = 0 ; i < n; ++i) {
        int num = 0;
        scanf_s("%d", &num);
        nums.emplace_back(num);
    }

    Solution sol;
    std::vector<int> res = sol.GetRes(nums);
    for (int cnt : res) {
        printf("%d ", cnt);
    }
    
    return 0;
}
