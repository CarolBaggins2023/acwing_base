#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> Mul(const std::vector<int> &a, int b) {
        int res = 0;
        std::vector<int> c;
        for (int i = 0; i < a.size() || res > 0; ++i) {
            if (i < a.size()) {
                res += a[i] * b;
            }
            c.emplace_back(res % 10);
            res /= 10;
        }

        while (c.size() > 1 && c.back() == 0) {
            c.pop_back();
        }
        return c;
    }
};

int main(int argc, char* argv[])
{
    std::string a;
    int b;
    std::cin >> a;
    scanf_s("%d", &b);

    std::vector<int> va;
    for (int i = a.size() - 1; i >= 0; --i) {
        va.emplace_back(a[i] - '0');
    }

    Solution sol;
    std::vector<int> res = sol.Mul(va, b);
    for (int i = res.size() - 1; i >= 0; --i) {
        printf("%d", res[i]);
    }
    
    return 0;
}
