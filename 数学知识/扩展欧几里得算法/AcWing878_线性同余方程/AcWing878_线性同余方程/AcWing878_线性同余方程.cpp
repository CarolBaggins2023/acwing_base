#include <iostream>

class Solution {

public:

    int EXGCD(int a, int b, int &x, int &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int xp = 0, yp = 0;
        int gcd = EXGCD(b, a % b, xp, yp);
        x = yp;
        y = xp - a / b * yp;
        return gcd;
    }
    
    int LCE(int a, int b, int m, bool &flag) {
        // a * x + m * y = b
        
        // a * x + m * y = gcd(a, m)
        int x0 = 0, y0 = 0;
        int gcd = EXGCD(a, m, x0, y0);

        if (b % gcd != 0) {
            flag = false;
            return -1;
        }

        flag = true;
        long long xp = static_cast<long long>(x0) * b / gcd % m;
        return xp;
    }
};

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;

    Solution sol;
    while (n--) {
        int a = 0, b = 0, m = 0;
        bool flag = false;
        std::cin >> a >> b >> m;
        int res = sol.LCE(a, b, m, flag);
        if (flag) {
            std::cout << res << std::endl;
        } else {
            std::cout << "impossible" << std::endl;
        }
    }
    
    return 0;
}
