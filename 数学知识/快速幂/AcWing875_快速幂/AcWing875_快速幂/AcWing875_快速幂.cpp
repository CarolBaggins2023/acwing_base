#include <iostream>

class Solution {

public:

    long long Couting(long long a, long long b, long long p) {
        long long res = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                res = res * a % p;
            }
            a = a * a % p;
            b >>= 1;
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
        long long a = 0, b = 0, p = 0;
        std::cin >> a >> b >> p;
        std::cout << sol.Couting(a, b, p) << std::endl;
    }
    
    return 0;
}
