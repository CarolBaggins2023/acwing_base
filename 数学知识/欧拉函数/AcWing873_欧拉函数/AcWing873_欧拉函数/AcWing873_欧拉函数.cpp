#include <iostream>
#include <unordered_map>

class Solution {

public:

    std::unordered_map<int, int> GetPrimes(int n) {
        std::unordered_map<int, int> primes;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i != 0) {
                continue;
            }

            primes.insert({i, 0});
            while (n % i == 0) {
                ++primes[i];
                n /= i;
            }
        }
        if (n > 1) {
            primes.insert({n, 1});
        }

        return primes;
    }

    long long EulerFunction(int n, const std::unordered_map<int, int> &primes) {
        long long res = n;
        for (std::pair<int, int> p : primes) {
            res = res * (p.first - 1) / p.first;
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
        int a = 0;
        std::cin >> a;
        std::cout << sol.EulerFunction(a, sol.GetPrimes(a)) << std::endl;
    }
    
    return 0;
}
