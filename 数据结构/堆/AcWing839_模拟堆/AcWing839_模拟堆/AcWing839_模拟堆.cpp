#include <utility>
#include <iostream>
#include <vector>

class MinHeap {
public:
    
    MinHeap() : nums(std::vector<int>()), order2idx(std::vector<int>(MaxSize)), idx2order(std::vector<int>(MaxSize)) {}

    void Insert(int x, int k) {
        nums.emplace_back(x);
        order2idx[k] = nums.size() - 1;
        idx2order[nums.size() - 1] = k;
        AdjustUp(nums.size() - 1);
    }

    int GetMin() {
        return nums[0];
    }

    void DeleteMin() {
        Swap(0, nums.size() - 1);
        nums.pop_back();
        AdjustDown(0);
    }

    void Delete(int k) {
        int idx = order2idx[k];
        Swap(idx, nums.size() - 1);
        nums.pop_back();
        AdjustDown(idx);
        AdjustUp(idx);
    }

    void Modify(int k, int x) {
        int idx = order2idx[k];
        nums[idx] = x;
        AdjustDown(idx);
        AdjustUp(idx);
    }

    const int MaxSize = 100001;

private:
    
    void AdjustDown(int a) {
        int left_child = 2 * a + 1, right_child = 2 * a + 2;
        int min_child = -1;
        if (right_child < nums.size()) {
            min_child = nums[left_child] < nums[right_child] ? left_child : right_child;
        } else if (left_child < nums.size()) {
            min_child = left_child;
        }
        if (min_child > 0 && nums[min_child] < nums[a]) {
            Swap(a, min_child);
            AdjustDown(min_child);
        }
    }

    void AdjustUp(int a) {
        if (a == 0) {
            return;
        }
        
        int parent = (a % 2) ? a / 2 : a / 2 - 1;
        if (nums[a] < nums[parent]) {
            Swap(a, parent);
            AdjustUp(parent);
        }
    }

    void Swap(int a, int b) {
        std::swap(nums[a], nums[b]);
        std::swap(idx2order[a], idx2order[b]);
        std::swap(order2idx[idx2order[a]], order2idx[idx2order[b]]);
    }
    
    std::vector<int> nums;
    std::vector<int> order2idx, idx2order;
};

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;

    MinHeap *heap = new MinHeap();
    int order = 1;
    while (n--) {
        std::string op;
        std::cin >> op;
        if (op == "I") {
            int x = 0;
            std::cin >> x;
            heap->Insert(x, order++);
        } else if (op == "PM") {
            std::cout << heap->GetMin() << std::endl;
        } else if (op == "DM") {
            heap->DeleteMin();
        } else if (op == "D") {
            int k = 0;
            std::cin >> k;
            heap->Delete(k);
        } else if (op == "C") {
            int k = 0, x = 0;
            std::cin >> k >> x;
            heap->Modify(k, x);
        } else {
            break;
        }
    }
    
    return 0;
}
