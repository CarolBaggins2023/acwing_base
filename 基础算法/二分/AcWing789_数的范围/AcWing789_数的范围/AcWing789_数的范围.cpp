#include <iostream>
#include <vector>

class Solution {
public:
    int FindBegin(const std::vector<int> &nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        if (nums[l] != k) {
            return -1;
        }
        return l;
    }

    int FindEnd(const std::vector<int> &nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (nums[mid] <= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        if (nums[l] != k) {
            return -1;
        }
        return l;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    
    int n = 0, q = 0;
    scanf_s("%d %d", &n, &q);
    std::vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int num = 0;
        scanf_s("%d", &num);
        nums.emplace_back(num);
    }
    for (int i = 0; i < q; ++i) {
        int k = 0;
        scanf_s("%d", &k);
        printf("%d %d\n", sol.FindBegin(nums, k), sol.FindEnd(nums, k));
    }
    
    return 0;
}
