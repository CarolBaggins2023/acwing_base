#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> Add(const std::vector<int> &a, const std::vector<int> &b) {
       if (a.size() < b.size()) {
           return Add(b, a);
       }

        int carry = 0;
        std::vector<int> c;
        for (int i = 0; i < a.size(); ++i) {
            carry += a[i];
            if (i < b.size()) {
                carry += b[i];
            }
            c.emplace_back(carry % 10);
            carry /= 10;
        }
        if (carry > 0) {
            c.emplace_back(carry);
        }
        return c;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    std::string a, b;
    std::vector<int> va, vb;
    std::cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; --i) {
        va.emplace_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; --i) {
        vb.emplace_back(b[i] - '0');
    }
    
    std::vector<int> res = sol.Add(va, vb);
    for (int i = res.size() - 1; i >= 0; --i) {
        std::printf("%d", res[i]);
    }
    
    return 0;
}
