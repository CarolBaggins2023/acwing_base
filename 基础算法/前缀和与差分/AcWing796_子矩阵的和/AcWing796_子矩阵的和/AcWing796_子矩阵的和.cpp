#include <iostream>
#include <vector>

class Solution {
public:
    Solution(const std::vector<std::vector<int>> &nums, int n, int m) : Sums(std::vector<std::vector<int>>(n + 1, std::vector<int>(m + 1, 0))) {
        // Sums[i][j] = Sums[i - 1][j] + Sums[i][j - 1] - Sums[i - 1][j - 1] + nums[i][j], i: [0, n), j: [0, m)
        // after explore, Sums[i + 1][j + 1] = Sums[i][j + 1] + Sums[i + 1][j] - Sums[i][j] + nums[i][j], i: [0, n), j: [0, m)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                Sums[i + 1][j + 1] = Sums[i][j + 1] + Sums[i + 1][j] - Sums[i][j] + nums[i][j];
            }
        }
    }

    int CalSum(int x1, int y1, int x2, int y2) {
        return Sums[x2][y2] - Sums[x1 - 1][y2] - Sums[x2][y1 - 1] + Sums[x1 - 1][y1 - 1];
    }

    void Print() {
        for (int i = 1; i < Sums.size(); ++i) {
            for (int j = 1; j < Sums[0].size(); ++j) {
                std::cout << Sums[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    std::vector<std::vector<int>> Sums;
};

int main(int argc, char* argv[])
{
    int n, m, q;
    scanf_s("%d %d %d", &n, &m, &q);

    std::vector<std::vector<int>> nums(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf_s("%d", &nums[i][j]);
        }
    }

    Solution sol(nums, n, m);
    // sol.Print();
    int x1, y1, x2, y2;
    for (int i = 0; i < q; ++i) {
        scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", sol.CalSum(x1, y1, x2, y2));
    }
    
    return 0;
}
