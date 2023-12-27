#include <iostream>
#include <string>
#include <vector>

class HashList {
    
public:

    HashList() : nums(std::vector<std::vector<int>> (max_n, std::vector<int>())) {}

    void Insert(int x) {
        int idx = (x % max_n + max_n) % max_n;
        nums[idx].emplace_back(x);
    }

    bool Query(int x) {
        int idx = (x % max_n + max_n) % max_n;
        for (int num : nums[idx]) {
            if (num == x) {
                return true;
            }
        }
        return false;
    }
    
private:

    std::vector<std::vector<int>> nums;

    static const int max_n = 1e5 + 3;
};

class HashList2 {
    
public:

    HashList2() : nums(std::vector<int> (max_n, 0x3f3f3f3f)) {}

    void Insert(int x) {
        int idx = (x % max_n + max_n) % max_n;
        while (nums[idx] != 0x3f3f3f3f && nums[idx] != x) {
            ++idx;
            if (idx == nums.size()) {
                idx = 0;
            }
        }
        nums[idx] = x;
    }

    bool Query(int x) {
        int idx = (x % max_n + max_n) % max_n;
        while (nums[idx] != 0x3f3f3f3f && nums[idx] != x) {
            ++idx;
            if (idx == nums.size()) {
                idx = 0;
            }
        }
        return nums[idx] == x;
    }
    
private:

    std::vector<int> nums;

    static const int max_n = 2e5 + 3;

    static const int null_num = 0x3f3f3f3f;
};

int main(int argc, char* argv[])
{
    HashList2 hl;

    int n = 0;
    std::cin >> n;
    while (n--) {
        std::string op;
        int x = 0;
        std::cin >> op >> x;
        if (op == "I") {
            hl.Insert(x);
        } else if (op == "Q") {
            std::cout << (hl.Query(x) ? "Yes" : "No") << std::endl;
        } else {
            break;
        }
    }
    
    return 0;
}
