#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class TrieNode {
public:
    TrieNode() : data(-1), child(nullptr), sib(nullptr) {}
    TrieNode(int _data) : data(_data), child(nullptr), sib(nullptr) {}
    
    int data;
    TrieNode *child, *sib;
};

class TrieTree {
public:
    TrieTree() : head(new TrieNode()) {}

    TrieNode* FindChild(TrieNode *node, int x) {
        TrieNode *child_node = node->child;
        while (child_node && child_node->data != x) {
            child_node = child_node->sib;
        }
        return child_node;
    }

    // 没必要把数转换成二进制串再传入Insert和Search
    // 因为数对应的二进制串的每一位都可以用(num >> i) & 1得到
    void Insert(int num) {
        TrieNode *node = head;
        for (int i = 30; i >= 0; --i) {
            int x = (num >> i) & 1;
            TrieNode *child_node = FindChild(node, x);
            if (child_node) {
                node = child_node;
            } else {
                TrieNode *new_node = new TrieNode(x);
                new_node->sib = node->child;
                node->child = new_node;
                node = new_node;
            }
        }
    }

    int Search(int num) {
        int res = 0;
        TrieNode *node = head;
        for (int i = 30; i >= 0; --i) {
            int x = (num >> i) & 1;
            TrieNode *reverse_child_node = FindChild(node, 1 - x);
            if (reverse_child_node) {
                res = res * 2 + 1;
                node = reverse_child_node;
            } else {
                res *= 2;
                node = FindChild(node, x);
            }
        }
        return res;
    }
    
    TrieNode *head;
};

int main(int argc, char* argv[])
{
    int N = 0;
    std::cin >> N;

    std::vector<int> nums;
    while (N--) {
        int A = 0;
        std::cin >> A;
        nums.emplace_back(A);
    }

    TrieTree *t = new TrieTree();
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        t->Insert(nums[i]);
        res = std::max(res, t->Search(nums[i]));
    }
    std::cout << res;
    
    return 0;
}
