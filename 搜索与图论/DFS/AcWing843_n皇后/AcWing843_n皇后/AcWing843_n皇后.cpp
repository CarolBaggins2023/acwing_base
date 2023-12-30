#include <iostream>
#include <vector>

class Solution {
    
public:
    
    void Print(int n, const std::vector<int> &path) {
        for (int idx = 0, k = 0; idx < n * n; ++idx) {
            if (idx == path[k]) {
                ++k;
                std::cout << "Q";
            } else {
                std::cout << ".";
            }
            if (idx % n == n - 1) {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    
    void BackTracking(int n, int start_line, std::vector<int> &used_col, std::vector<int> &used_dg, std::vector<int> &used_udg, std::vector<int> &path) {
        if (path.size() == n) {
            Print(n, path);
        }

        for (int i = start_line; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (used_col[j] || used_dg[j + i] || used_udg[j - i + n]) {
                    continue;
                }
                used_col[j] = true;
                used_dg[j + i] = true;
                used_udg[j - i + n] = true;
                path.emplace_back(i * n + j);
                BackTracking(n, i + 1, used_col, used_dg, used_udg, path);
                path.pop_back();
                used_udg[j - i + n] = false;
                used_dg[j + i] = false;
                used_col[j] = false;
            }
        }
    }
};

int main(int argc, char* argv[])
{
    // used要初始化
    int n = 0;
    std::cin >> n;

    std::vector<int> used_col(n, false), used_dg(2 * n, false), used_udg(2 * n, false);
    std::vector<int> path;
    Solution sol;
    sol.BackTracking(n, 0, used_col, used_dg, used_udg, path);
    
    return 0;
}
