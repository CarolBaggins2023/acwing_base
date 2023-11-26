#include <iostream>
#include <vector>

class Solution {
public:
    Solution(const std::vector<int> &nums) : diff(std::vector<int>(nums.size() + 1, 0)) {
        // 末尾多出一位，用于处理Add()中的diff[r + 1]
        // int n = nums.size();
        // diff[0] = nums[0];
        // for (int i = 1; i < n; ++i) {
        //     diff[i] = nums[i] - nums[i - 1];
        // }
        // 这样的构造方式可能更好
        // 因为diff初始值全为0，所以直接计算diff[i] = nums[i] - nums[i - 1]，相当于在范围[i, i]上增加nums[i]
        for (int i = 0; i < nums.size(); ++i) {
            Add(i, i, nums[i]);
        }
    }

    void Add(int l, int r, int c) {
        diff[l] += c;
        diff[r + 1] -= c;
    }

    void Print() {
        // 注意diff比nums多一位
        int pre_sum = 0;
        for (int i = 0; i < diff.size() - 1; ++i) {
            pre_sum += diff[i];
            std::printf("%d ", pre_sum);
        }
    }
    
    std::vector<int> diff;
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::vector<int> nums;
    scanf_s("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf_s("%d", &num);
        nums.emplace_back(num);
    }

    Solution sol(nums);
    for (int i = 0; i < m; ++i) {
        int l = 0, r = 0, c = 0;
        scanf_s("%d %d %d", &l, &r, &c);
        sol.Add(l - 1, r - 1, c);
    }
    sol.Print();
    
    return 0;
}
