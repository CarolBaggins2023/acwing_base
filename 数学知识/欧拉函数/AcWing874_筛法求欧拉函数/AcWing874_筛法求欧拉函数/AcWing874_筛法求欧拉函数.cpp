#include <iostream>
#include <vector>

class Solution {

public:

    long long EulerFuncSum(int n) {
        std::vector<int> primes;
        std::vector<bool> is_composite(n + 1, false);
        std::vector<long long> euler_func(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            if (!is_composite[i]) {
                primes.emplace_back(i);
                euler_func[i] = i - 1;
            }
            for (int j : primes) {
                if (i * j > n) {
                    break;
                }
                is_composite[i * j] = true;
                if (i % j == 0) {
                    euler_func[i * j] = j * euler_func[i];
                    break;
                } else {
                    euler_func[i * j] = (j - 1) * euler_func[i];
                }
            }
        }

        long long res = 1;
        for (long long i : euler_func) {
            res += i;
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    int n = 0;
    Solution sol;
    std::cin >> n;
    std::cout << sol.EulerFuncSum(n);
    
    return 0;
}
