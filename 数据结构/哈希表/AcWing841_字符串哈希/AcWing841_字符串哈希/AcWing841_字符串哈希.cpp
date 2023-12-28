#include <cmath>
#include <iostream>
#include <vector>

// 假设不会发生哈希冲突
class StringHash {

public:

    StringHash(std::string input_s) : s(input_s) {
        unsigned long long num = 0, p_pow = 1;
        for (int i = 0; i < s.size(); ++i) {
            num = num * p + s[i];
            hash.emplace_back(num);
            
            p_pows.emplace_back(p_pow);
            p_pow *= p;
        }
    }

    unsigned long long SubStringHash(int l, int r) {
        if (l == 0) {
            return hash[r];
        }
        
        unsigned long long hash_r = hash[r], hash_l = hash[l - 1];
        // return hash_r - hash_l * static_cast<unsigned long long>(std::pow(p, r - l + 1));
        return hash_r - hash_l * p_pows[r - l + 1];
    }

private:

    std::string s;
    
    std::vector<unsigned long long> hash;

    static const int p = 131;

    std::vector<unsigned long long> p_pows;
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    
    std::string s;
    std::cin >> s;

    StringHash *sh = new StringHash(s);
    int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
    while (m--) {
        std::cin >> l1 >> r1 >> l2 >> r2;
        std::cout << (sh->SubStringHash(l1 - 1, r1 - 1) == sh->SubStringHash(l2 - 1, r2 - 1) ? "Yes" : "No") << std::endl;
    }
    
    return 0;
}
