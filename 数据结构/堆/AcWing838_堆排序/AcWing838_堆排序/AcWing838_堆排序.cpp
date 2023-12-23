#include <iostream>
#include <vector>

class MinHeap {
public:
    MinHeap() : nums(std::vector<int>()) {}

    void AdjustHeap(int idx, int cnt_sorted) {
        int n = nums.size() - cnt_sorted;
        int left_child = 2 * idx + 1, right_child = 2 * idx + 2;
        int min_child = 0;
        if (left_child < n && right_child < n) {
            min_child = nums[left_child] < nums[right_child] ? left_child : right_child;
        } else if (left_child < n) {
            min_child = left_child;
        } else {
            min_child = -1;
        }
        if (min_child >= 0 && nums[min_child] < nums[idx]) {
            std::swap(nums[idx], nums[min_child]);
            AdjustHeap(min_child, cnt_sorted);
        }
    }

    void HeapSort(int m) {
        int cnt_sorted = 0;
        for (int i = nums.size() / 2 - 1; i >= 0; --i) {
            AdjustHeap(i, 0);
        }
        
        for (int i = 0; i < m; ++i) {
            // std::cout << nums[0] << " ";
            
            std::swap(nums[0], nums[nums.size() - i - 1]);
            ++cnt_sorted;
            
            AdjustHeap(0, cnt_sorted);
        }
    }

    void Print(int m) {
        int i = nums.size() - 1;
        while (m--) {
            std::cout << nums[i--] << " ";
        }
    }
    
    std::vector<int> nums;
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    
    MinHeap *heap = new MinHeap();
    for (int i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;
        heap->nums.emplace_back(x);
    }

    heap->HeapSort(m);
    heap->Print(m);
    
    return 0;
}
