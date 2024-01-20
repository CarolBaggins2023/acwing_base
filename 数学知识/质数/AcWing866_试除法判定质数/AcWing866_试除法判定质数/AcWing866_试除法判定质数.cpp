#include <iostream>
#include <valarray>

class Solution {

public:

    bool JudgePrime(int n) {
        if (n < 2) {
            return false;
        }

        int n_sqrt = static_cast<int>(std::sqrt(n));
        for (int i = 2; i <= n_sqrt; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    } 
};

int main(int argc, char* argv[])
{
    Solution sol;
    int n = 0;
    std::cin >> n;
    while (n--) {
        int x;
        std::cin >> x;
        std::cout << (sol.JudgePrime(x) ? "Yes" : "No") << std::endl;
    }
    
    return 0;
}
