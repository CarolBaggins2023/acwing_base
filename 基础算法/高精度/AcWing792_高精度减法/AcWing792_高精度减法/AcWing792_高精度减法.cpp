#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool cmp(const std::vector<int> &a, const std::vector<int> &b) {
        if (a.size() != b.size()) {
            return a.size() > b.size();
        }

        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }

        return true;
    }
    
    std::vector<int> Sub(const std::vector<int> &a, const std::vector<int> &b) {
        std::vector<int> c;
        int borrow = 0;
        for (int i = 0; i < a.size(); ++i) {
            int res = a[i] - borrow;
            if (i < b.size()) {
                res -= b[i];
            }
            if (res < 0) {
                c.emplace_back(res + 10);
                borrow = 1;
            } else {
                c.emplace_back(res);
                borrow = 0;
            }
        }
        while (c.size() > 1 && c.back() == 0) {
            c.pop_back();
        }
        return c;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    std::string a, b;
    std::cin >> a >> b;

    std::vector<int> va, vb, res;
    for (int i = a.size() - 1; i >= 0; --i) {
        va.emplace_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; --i) {
        vb.emplace_back(b[i] - '0');
    }

    if (sol.cmp(va, vb)) {
        res = sol.Sub(va, vb);
        for (int i = res.size() - 1; i >= 0; --i) {
            std::printf("%d", res[i]);
        }
    } else {
        res = sol.Sub(vb, va);
        std::printf("-");
        for (int i = res.size() - 1; i >= 0; --i) {
            std::printf("%d", res[i]);
        }
    }
    
    return 0;
}
