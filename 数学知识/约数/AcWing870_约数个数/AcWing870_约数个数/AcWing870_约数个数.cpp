#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {

public:

    Solution() : divisor_cnt(std::unordered_map<int, int>()) {}

    void GetDivisors(int n) {
        int sqrt_n = std::sqrt(n);
        for (int i = 2; i <= sqrt_n; ++i) {
            if (n % i == 0) {
                if (divisor_cnt.find(i) == divisor_cnt.end()) {
                    divisor_cnt.insert({i, 0});
                }
                while (n % i == 0) {
                    ++divisor_cnt[i];
                    n /= i;
                }
            }
        }
        if (n > 1) {
            if (divisor_cnt.find(n) == divisor_cnt.end()) {
                divisor_cnt.insert({n, 0});
            }
            ++divisor_cnt[n];
        }
    }

    long long GetRes() {
        long long res = 1;
        for (std::pair<int, int> p : divisor_cnt) {
            res = res * (p.second + 1) % static_cast<int>(1e9 + 7);
        }
        return res;
    }

    std::unordered_map<int, int> divisor_cnt;
};

int main(int argc, char* argv[])
{
    int n = 0;
    Solution sol;
    std::cin >> n;
    while (n--) {
        int a = 0;
        std::cin >> a;
        sol.GetDivisors(a);
    }
    std::cout << sol.GetRes();
    
    return 0;
}
