#include <algorithm>
#include <iostream>
#include <vector>

class Solution {

public:

    std::vector<int> GetDivisors(int n) {
        std::vector<int> divisors;
        int sqrt_n = std::sqrt(n);
        for (int i = 1; i <= sqrt_n; ++i) {
            if (n % i == 0) {
                divisors.emplace_back(i);
                int j = n / i;
                if (i != j) {
                    divisors.emplace_back(j);
                }
            }
        }
        return divisors;
    }
};

int main(int argc, char* argv[])
{
    int n = 0;
    Solution sol;
    std::cin >> n;
    while (n--) {
        int a = 0;
        std::cin >> a;
        std::vector<int> divisors = sol.GetDivisors(a);
        std::sort(divisors.begin(), divisors.end(), std::less<int>());
        for (int i : divisors) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
