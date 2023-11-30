#include <algorithm>
#include <iostream>
#include <thread>
#include <utility>
#include <vector>

class Solution {
public:
    int FindIdx(const std::vector<int> &idxs, int idx) {
        int l = 0, r = idxs.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (idxs[mid] >= idx) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    std::vector<int> CalPreSum(const std::vector<int> &nums) {
        std::vector<int> pre_sum(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            pre_sum[i] = sum;
        }
        return pre_sum;
    }
    
    std::vector<int> GetRes(std::vector<int> idxs, const std::vector<std::pair<int, int>> &idx_num, const std::vector<std::pair<int, int>> &query) {
        std::sort(idxs.begin(), idxs.end());
        idxs.erase(std::unique(idxs.begin(), idxs.end()), idxs.end());

        std::vector<int> nums(idxs.size(), 0);
        for (std::pair<int, int> p : idx_num) {
            int i = FindIdx(idxs, p.first);
            nums[i] += p.second;
        }

        std::vector<int> pre_sum = CalPreSum(nums);

        std::vector<int> res;
        for (std::pair<int, int> p : query) {
            int i_r = FindIdx(idxs, p.second), i_l = FindIdx(idxs, p.first);
            res.emplace_back(pre_sum[i_r] - (i_l ? pre_sum[i_l - 1] : 0));
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::vector<int> idxs;
    std::vector<std::pair<int, int>> idx_num, query;
    scanf_s("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int x = 0, c = 0;
        scanf_s("%d %d", &x, &c);
        idx_num.emplace_back(x, c);
        idxs.emplace_back(x);
    }
    for (int i = 0; i < m; ++i) {
        int l = 0, r = 0;
        scanf_s("%d %d", &l, &r);
        query.emplace_back(l, r);
        idxs.emplace_back(l);
        idxs.emplace_back(r);
    }

    Solution sol;
    std::vector<int> res = sol.GetRes(idxs, idx_num, query);
    for (int i : res) {
        printf("%d\n", i);
    }
    
    return 0;
}
