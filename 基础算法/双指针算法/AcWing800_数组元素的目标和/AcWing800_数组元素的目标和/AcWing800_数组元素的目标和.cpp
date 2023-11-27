#include <iostream>
#include <utility>
#include <vector>

class Solution {
public:
    std::vector<std::pair<int, int>> Count(const std::vector<int> &va, const std::vector<int> &vb, int target) {
        std::vector<std::pair<int, int>> res;
        for (int i = 0, j = vb.size() - 1; i < va.size(); ++i) {
            while (va[i] + vb[j] > target && j > 0) {
                --j;
            }
            if (va[i] + vb[j] == target) {
                res.emplace_back(i, j);
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0, x = 0;
    std::vector<int> va, vb;
    scanf_s("%d %d %d", &n, &m, &x);
    for (int i = 0; i < n; ++i) {
        int num = 0;
        scanf_s("%d", &num);
        va.emplace_back(num);
    }
    for (int j = 0; j < m; ++j) {
        int num = 0;
        scanf_s("%d", &num);
        vb.emplace_back(num);
    }

    Solution sol;
    std::vector<std::pair<int, int>> res = sol.Count(va, vb, x);
    for (std::pair<int, int> p : res) {
        printf("%d %d\n", p.first, p.second);
    }
    
    return 0;
}
