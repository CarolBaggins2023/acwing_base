#include <iostream>
#include <vector>

class Solution {

public:

    int CompleteSnapsack(int volume, const std::vector<int> &v, const std::vector<int> &w) {
        std::vector<int> dp(volume + 1, 0);
        for (int i = 0; i < v.size(); ++i) {
            for (int j = v[i]; j < dp.size(); ++j) {
                dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
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
    std::vector<int> v, w;
    while (n--) {
        int vi = 0, wi = 0;
        std::cin >> vi >> wi;
        v.emplace_back(vi);
        w.emplace_back(wi);
    }
    std::cout << sol.CompleteSnapsack(volume, v, w);
    
    return 0;
}
