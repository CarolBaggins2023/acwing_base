#include <iostream>
#include <deque>
#include <vector>

void GetRes1(const std::vector<int> &nums, int k, std::vector<int> &min_num, std::vector<int> &max_num) {
    std::deque<int> que;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > k - 1 && nums[i - k] == que.front()) {
            que.pop_front();
        }

        while (!que.empty() && que.back() > nums[i]) {
            que.pop_back();
        }
        que.push_back(nums[i]);

        if (i >= k - 1) {
            min_num.emplace_back(que.front());
        }
    }

    que.clear();
    for (int i = 0; i < nums.size(); ++i) {
        if (i > k - 1 && nums[i - k] == que.front()) {
            que.pop_front();
        }

        while (!que.empty() && que.back() < nums[i]) {
            que.pop_back();
        }
        que.push_back(nums[i]);

        if (i >= k - 1) {
            max_num.emplace_back(que.front());
        }
    }
}

int main(int argc, char* argv[])
{
    int n = 0, k = 0;
    std::vector<int> nums;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int num = 0;
        std::cin >> num;
        nums.emplace_back(num);
    }

    std::vector<int> min_num, max_num;
    GetRes1(nums, k, min_num, max_num);
    for (int i : min_num) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i : max_num) {
        std::cout << i << " ";
    }
    
    return 0;
}
