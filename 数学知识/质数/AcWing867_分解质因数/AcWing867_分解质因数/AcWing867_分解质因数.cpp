#include <iostream>
#include <valarray>
#include <vector>

class Solution {

public:

    std::vector<std::pair<int, int>> PrimeFactorization(int n) {
        std::vector<std::pair<int, int>> res;
        if (n < 2) {
            return res;
        }

        int n_sqrt = std::sqrt(n);
        // 因为后面有n /= i，所以循环的后面部分可能会有很多次执行if (n % i != 0) {continue;}
        for (int i = 2; i <= n_sqrt; ++i) {
            if (n % i != 0) {
                continue;
            }
            int cnt = 0;
            while (n % i == 0) {
                ++cnt;
                n /= i;
            }
            res.emplace_back(i, cnt);
        }
        if (n > 1) {
            res.emplace_back(n, 1);
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;

    Solution sol;
    while (n--) {
        int x = 0;
        std::cin >> x;
        std::vector<std::pair<int, int>> res = sol.PrimeFactorization(x);
        for (std::pair<int, int> p : res) {
            std::cout << p.first << " " << p.second << std::endl;
        }
        std::cout << std::endl;
    }
    
    return 0;
}
