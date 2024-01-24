#include <iostream>
#include <vector>

class Solution {

public:

    std::vector<int> GetPrimes1(int n) {
        std::vector<int> primes;
        std::vector<bool> is_composite(n + 1, false);
        for (int i = 2; i <= n; ++i) {
            if (!is_composite[i]) {
                primes.emplace_back(i);
                for (int j = 2 * i; j <= n; j += i) {
                    is_composite[j] = true;
                }
            }
        }

        return primes;
    }

    std::vector<int> GetPrimes2(int n) {
        std::vector<int> primes;
        std::vector<bool> is_composite(n + 1, false);
        for (int i = 2; i <= n; ++i) {
            if (!is_composite[i]) {
                primes.emplace_back(i);
            }
            for (int j : primes) {
                if (i * j > n) {
                    break;
                }
                is_composite[i * j] = true;
                if (i % j == 0) {
                    break;
                }
            }
        }
        return primes;
    }

    int GetPrimeCnt(int n) {
        std::vector<int> primes = GetPrimes2(n);
        return primes.size();
    }
};

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;

    Solution sol;
    std::cout << sol.GetPrimeCnt(n);
    
    return 0;
}
