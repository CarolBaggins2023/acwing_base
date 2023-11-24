#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Solution {
public:
    void Reverse(std::vector<int> &v) {
        if (v.empty()) {
            return;
        }

        int i = 0, j = v.size() - 1;
        while (i < j) {
            std::swap(v[i], v[j]);
            ++i;
            --j;
        }
    }
    
    std::pair<std::vector<int>, int> Div(const std::vector<int> &a, int b) {
        int res = 0;
        std::vector<int> c;
        for (int i = 0; i < a.size(); ++i) {
            res = res * 10 + a[i];
            c.emplace_back(res / b);
            res = res % b;
        }
        // std::reverse(c.begin(), c.end());
        // while (c.size() > 1 && c.back() == 0) {
        //     c.pop_back();
        // }
        // std::reverse(c.begin(), c.end());
        // 编译器不让直接用std::reverse
        Reverse(c);
        while (c.size() > 1 && c.back() == 0) {
            c.pop_back();
        }
        Reverse(c);
        return std::make_pair(c, res);
    }
};

int main(int argc, char* argv[])
{
    std::string a;
    int b;
    std::cin >> a;
    scanf_s("%d", &b);

    std::vector<int> va;
    for (const char c : a) {
        va.emplace_back(c - '0');
    }
    
    Solution sol;
    std::pair<std::vector<int>, int> p = sol.Div(va, b);
    std::vector<int> res1 = p.first;
    int res2 = p.second;
    for (const int i : res1) {
        printf("%d", i);
    }
    printf("\n%d", res2);
    
    return 0;
}
