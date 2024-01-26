#include <iostream>

class Solution {

public:

    // 将a和b的最大公约数（greatest common divisor）表示为gcd(a, b)
    // 则有结论表明，gcd(a, b) == gcd(b, a % b)
    int GCD(int a, int b) {
        if (a % b == 0) {
            return b;
        }
        return GCD(b, a % b);
    }
};

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;

    Solution sol;
    while (n--) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        std::cout << sol.GCD(a, b) << std::endl;
    }
    
    return 0;
}
