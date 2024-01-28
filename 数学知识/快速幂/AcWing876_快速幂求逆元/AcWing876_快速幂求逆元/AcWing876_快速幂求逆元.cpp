#include <iostream>

class Solution {

public:

    long long InverseElem(long long a, long long b, long long m) {
        if (a % m == 0) {
            return -1;
        }
        
        long long res = 1;
        while (b > 0) {
            if ((b & 1) > 0) {
                res = res * a % m;
            }
            b >>= 1;
            a = a * a % m;
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
        int a = 0, p = 0;
        std::cin >> a >> p;
        long long res = sol.InverseElem(a, p - 2, p);
        if (res == -1) {
            std::cout << "impossible" << std::endl;
        } else {
            std::cout << res << std::endl;
        }
    }
    
    return 0;
}
