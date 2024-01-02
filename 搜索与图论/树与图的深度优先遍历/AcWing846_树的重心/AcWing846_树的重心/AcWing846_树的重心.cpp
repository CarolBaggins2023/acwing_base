#include <iostream>
#include <vector>

class ArcNode {

public:

    ArcNode(int _idx, ArcNode *_next) : idx(_idx), next(_next) {}

    int idx;
    ArcNode *next;
};

class AdjacencyListNode {

public:

    AdjacencyListNode() : data(-1), first_node(nullptr) {}

    int data;
    ArcNode *first_node;
};

class AdjacencyList {

public:
    
    AdjacencyList(int n) : list(std::vector<AdjacencyListNode>(n)) {
        for (int i = 0; i < n; ++i) {
            // 因为这题的n个数是1到n，所以data是下标+1
            list[i].data = i + 1;
        }
    }

    int FindIdx(int x) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i].data == x) {
                return i;
            }
        }
        return -1;
    }

    void AddArc(int a, int b) {
        // int idx_a = FindIdx(a), idx_b = FindIdx(b);
        // 因为这题的n个数是1到n，所以下标是data-1
        int idx_a = a - 1, idx_b = b - 1;
        ArcNode *new_node = new ArcNode(idx_b, list[idx_a].first_node);
        list[idx_a].first_node = new_node;
    }

    std::vector<AdjacencyListNode> list;
};

class Solution {

public:

    Solution(AdjacencyList _al) : al(_al), res(0x3f3f3f3f) {}

    int BFS(int cur_idx, std::vector<bool> &visited) {
        int cnt_tree = 1;
        int max_block = 0;
        ArcNode *node = al.list[cur_idx].first_node;
        while (node) {
            if (visited[node->idx]) {
                node = node->next;
                continue;
            }
            
            int cnt_sub_tree = 0;
            visited[node->idx] = true;
            cnt_sub_tree = BFS(node->idx, visited);
            visited[node->idx] = false;
            cnt_tree += cnt_sub_tree;
            max_block = std::max(max_block, cnt_sub_tree);

            node = node->next;
        }
        max_block = std::max(max_block, static_cast<int>(al.list.size() - cnt_tree));
        res = std::min(res, max_block);

        return cnt_tree;
    }

    const AdjacencyList al;
    int res;
};

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;

    AdjacencyList al(n);
    for (int i = 0; i < n - 1; ++i) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        al.AddArc(a, b);
        al.AddArc(b, a);
    }

    Solution sol(al);
    std::vector<bool> visited(al.list.size(), false);
    sol.BFS(0, visited);
    std::cout << sol.res;
    
    return 0;
}
