#include <iostream>
#include <valarray>

class Solution {
public:
    double CalCubicRoot(double n) {
        double l = -10000.0, r = 10000.0;
        while (r - l > 1e-8) {
            double mid = (l + r) / 2;
            if (std::pow(mid, 3) > n) {
                r = mid;
            } else {
                l = mid;
            }
        }

        return l;
    }
};

int main(int argc, char* argv[])
{
    // 注意：float仅有7位有效数字，所以这里要用double或long double
    Solution sol;
    double n = 0.0;
    scanf_s("%lf", &n);
    std::printf("%.6lf", sol.CalCubicRoot(n));
    
    return 0;
}
