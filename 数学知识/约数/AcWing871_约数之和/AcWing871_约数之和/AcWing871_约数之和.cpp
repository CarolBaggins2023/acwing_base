#include <iostream>
#include <unordered_map>

class Solution {

public:

    Solution() : primes(std::unordered_map<long long, long long>()) {}

    void GetPrimes(long long n) {
        for (long long i = 2; i * i <= n; ++i) {
            if (n % i != 0) {
                continue;
            }
            
            if (primes.find(i) == primes.end()) {
                primes.insert({i, 0});
            }
            while (n % i == 0) {
                ++primes[i];
                n /= i;
            }
        }
        if (n > 1) {
            if (primes.find(n) == primes.end()) {
                primes.insert({n, 0});
            }
            ++primes[n];
        }
    }

    // 查看约数之和的公式
    long long GetPrimeSum() {
        long long res = 1;
        for (std::pair<long long, long long> p : primes) {
            long long sum = 0, cnt = p.second;
            while (cnt >= 0) {
                sum = (sum * p.first + 1) % static_cast<long long>(1e9 + 7);
                --cnt;
            }
            res = (res * sum) % static_cast<long long>(1e9 + 7);
        }
        return res;
    }

    std::unordered_map<long long, long long> primes;
};

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;

    Solution sol;
    while (n--) {
        long long x = 0;
        std::cin >> x;
        sol.GetPrimes(x);
    }
    std::cout << sol.GetPrimeSum();
    
    return 0;
}
