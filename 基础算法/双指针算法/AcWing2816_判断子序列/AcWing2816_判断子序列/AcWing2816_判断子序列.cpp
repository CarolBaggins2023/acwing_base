#include <iostream>
#include <vector>

class Solution {
public:
    bool Judge1(const std::vector<int> &a, const std::vector<int> &b) {
        // dp[i][j]以下标i结尾的序列a和以下标j结尾的序列b的子序列长度
        // if a[i] == b[j], dp[i][j] = dp[i - 1][j - 1] + 1
        // if a[i] != b[j], dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
        // dp[0][0]和dp[i][0]和dp[0][j]需要初始化
        std::vector<std::vector<int>> dp(a.size(), std::vector<int>(b.size(), 0));
        dp[0][0] = (a[0] == b[0]);
        for (int i = 1; i < a.size(); ++i) {
            dp[i][0] = std::max(static_cast<int>(a[i] == b[0]), dp[i - 1][0]);
        }
        for (int j = 1; j < b.size(); ++j) {
            dp[0][j] = std::max(static_cast<int>(a[0] == b[j]), dp[0][j - 1]);
        }

        for (int i = 1; i < a.size(); ++i) {
            for (int j = 1; j < b.size(); ++j) {
                if (a[i] == b[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[a.size() - 1][b.size() - 1] == a.size();
    }

    bool Judge2(const std::vector<int> &a, const std::vector<int> &b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        return i == a.size();
    }
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::vector<int> va, vb;
    scanf_s("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int num = 0;
        scanf_s("%d", &num);
        va.emplace_back(num);
    }
    for (int i = 0; i < m; ++i) {
        int num = 0;
        scanf_s("%d", &num);
        vb.emplace_back(num);
    }

    Solution sol;
    printf("%s", sol.Judge2(va, vb) ? "Yes" : "No");
    
    return 0;
}
