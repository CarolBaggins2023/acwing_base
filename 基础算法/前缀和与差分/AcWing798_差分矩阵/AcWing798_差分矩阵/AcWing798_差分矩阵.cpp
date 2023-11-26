#include <iostream>
#include <vector>

class Solution {
public:
    Solution(const std::vector<std::vector<int>> &nums) : diff(std::vector<std::vector<int>>(nums.size() + 1, std::vector<int>(nums[0].size() + 1, 0))) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[0].size(); ++j) {
                Add(i, j, i, j, nums[i][j]);
            }
        }
    }

    void Add(int x1, int y1, int x2, int y2, int c) {
        diff[x1][y1] += c;
        diff[x1][y2 + 1] -= c;
        diff[x2 + 1][y1] -= c;
        diff[x2 + 1][y2 + 1] += c;
    }

    void Print() {
        // sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + num[i][j]
        std::vector<std::vector<int>> sum(std::vector<std::vector<int>>(diff.size(), std::vector<int>(diff[0].size(), 0)));
        for (int i = 0; i < diff.size() - 1; ++i) {
            for (int j = 0; j < diff[0].size() - 1; ++j) {
                sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + diff[i][j];
            }
        }

        for (int i = 1; i < sum.size(); ++i) {
            for (int j = 1; j < sum[0].size(); ++j) {
                printf("%d ", sum[i][j]);
            }
            printf("\n");
        }
    }

    std::vector<std::vector<int>> diff;
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0, q = 0;
    scanf_s("%d %d %d", &n, &m, &q);

    std::vector<std::vector<int>> nums(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf_s("%d", &nums[i][j]);
        }
    }

    Solution sol(nums);
    for (int i = 0; i < q; ++i) {
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0, c = 0;
        scanf_s("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        sol.Add(x1 - 1, y1 - 1, x2 - 1, y2 - 1, c);
    }

    sol.Print();
    
    return 0;
}
