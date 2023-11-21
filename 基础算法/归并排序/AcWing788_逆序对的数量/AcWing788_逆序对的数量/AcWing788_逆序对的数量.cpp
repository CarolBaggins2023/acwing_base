#include <iostream>
#include <vector>

class Solution {
public:
    Solution() : cnt(0) {}
    
    void sort(std::vector<int> &nums, int l, int r, std::vector<int> &tmp) {
        if (l >= r) {
            return;
        }

        int mid = (l + r) / 2;
        sort(nums, l, mid, tmp);
        sort(nums, mid + 1, r, tmp);
        merge(nums, l, mid, r, tmp);
    }

    void merge(std::vector<int> &nums, int l, int mid, int r, std::vector<int> &tmp) {
        int i = l, j = mid + 1, t = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[t++] = nums[i++];
            } else {
                tmp[t++] = nums[j++];
                cnt += mid - i + 1;
            }
        }

        while (i <= mid) {
            tmp[t++] = nums[i++];
        }
        while (j <= r) {
            tmp[t++] = nums[j++];
        }

        for (i = l, t = 0; i <= r; ++i, ++t) {
            nums[i] = tmp[t];
        }
    }

    unsigned long cnt;
};

int main(int argc, char* argv[])
{
    int n;
    std::vector<int> nums;
    scanf_s("%d", &n);
    std::vector<int> tmp(n);
    for (int i = 0; i < n; ++i) {
        int num;
        scanf_s("%d", &num);
        nums.emplace_back(num);
    }
    Solution sol;
    sol.sort(nums, 0, n - 1, tmp);
    printf("%lu", sol.cnt);
    
    return 0;
}
