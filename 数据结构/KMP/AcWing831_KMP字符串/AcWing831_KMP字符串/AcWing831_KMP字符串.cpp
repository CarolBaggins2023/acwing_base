#include <iostream>
#include <string>
#include <vector>

std::vector<int> FindMatch(const std::string &p, const std::string &s) {
    int n = p.size(), m = s.size();
    std::vector<int> next(p.size(), 0);
    for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && p[i] != p[j]) {
            j = next[j - 1];
        }
        if (p[i] == p[j]) {
            ++j;
        }
        next[i] = j;
    }

    std::vector<int> res;
    for (int i = 0, j = 0; i < m; ++i) {
        while (j > 0 && s[i] != p[j]) {
            j = next[j - 1];
        }
        if(s[i] == p[j]) {
            ++j;
        }
        if (j == n) {
            res.emplace_back(i - p.size() + 1);
            j = next[j - 1];
        }
    }

    return res;
}

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::string p, s;
    scanf_s("%d", &n);
    std::cin >> p;
    scanf_s("%d", &m);
    std::cin >> s;

    std::vector<int> res = FindMatch(p, s);
    for (int i : res) {
        printf("%d ", i);
    }
    
    return 0;
}
