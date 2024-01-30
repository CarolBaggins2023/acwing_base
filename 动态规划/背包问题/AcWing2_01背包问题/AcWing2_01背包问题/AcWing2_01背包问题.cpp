#include <iostream>
#include <vector>

class Solution {

public:

    int ZeroOneKnapsack(int volume, const std::vector<int> &v, const std::vector<int> &w) {
        std::vector<int> res(volume + 1, 0);
        for (decltype(res.size()) j = v[0]; j < res.size(); ++j) {
            res[j] = w[0];
        }

        for (decltype(v.size()) i = 1; i < v.size(); ++i) {
            for (int j = res.size(); j >= 0; --j) {
                if (j < v[i]) {
                    break;
                }
                res[j] = std::max(res[j], res[j - v[i]] + w[i]);
            }
        }

        return res[res.size() - 1];
    }
};

int main(int argc, char* argv[])
{
    int n = 0, volume = 0;
    std::cin >> n >> volume;

    std::vector<int> v, w;
    while (n--) {
        int vi = 0, wi = 0;
        std::cin >> vi >> wi;
        v.emplace_back(vi);
        w.emplace_back(wi);
    }

    Solution sol;
    std::cout << sol.ZeroOneKnapsack(volume, v, w);
    
    return 0;
}
