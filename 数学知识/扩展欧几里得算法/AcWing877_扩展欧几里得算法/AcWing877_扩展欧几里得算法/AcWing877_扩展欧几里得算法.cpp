#include <iostream>

class Solution {

public:

    void ExGCD(int a, int b, int &x, int &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return;
        }

        int xp = 0, yp = 0;
        ExGCD(b, a % b, xp, yp);
        x = yp;
        y = xp - a / b * yp;
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

        int x = 0, y = 0;
        sol.ExGCD(a, b, x, y);
        std::cout << x << " " << y << std::endl;
    }
    
    return 0;
}
