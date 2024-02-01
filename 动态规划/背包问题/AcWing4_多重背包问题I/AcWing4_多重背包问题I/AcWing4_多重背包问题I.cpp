#include <iostream>
#include <vector>

class Solution {

public:

    int MultiKnapsack(int volume, const std::vector<int> &v, const std::vector<int> &w, const std::vector<int> &s) {
        std::vector<int> dp(volume + 1, 0);
        for (int i = 0; i < v.size(); ++i) {
            for (int j = volume; j >= v[i]; --j) {
                for (int k = 1; k <= s[i] && k * v[i] <= j; ++k) {
                    dp[j] = std::max(dp[j], dp[j - k * v[i]] + k * w[i]);
                }
            }
        }

        return dp[volume];
    }
};

int main(int argc, char* argv[])
{
    int n = 0, volume = 0;
    std::cin >> n >> volume;

    Solution sol;
    std::vector<int> v, w, s;
    while (n--) {
        int si = 0, vi = 0, wi = 0;
        std::cin >> vi >> wi >> si;
        v.emplace_back(vi);
        w.emplace_back(wi);
        s.emplace_back(si);
    }

    std::cout << sol.MultiKnapsack(volume, v, w, s);
    
    return 0;
}
