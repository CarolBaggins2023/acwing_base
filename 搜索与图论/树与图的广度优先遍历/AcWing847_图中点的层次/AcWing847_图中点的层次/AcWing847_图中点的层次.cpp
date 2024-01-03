#include <iostream>
#include <queue>
#include <utility>
#include <vector>

class ArcNode {

public:

    ArcNode(int _idx, ArcNode *_next) : idx(_idx), next(_next) {}

    int idx;
    ArcNode *next;
};

class ListNode {

public:

    ListNode() : data(-1), first_arc(nullptr) {}

    int data;
    ArcNode *first_arc;
};

class AdjacencyList {

public:

    AdjacencyList(int n) : list(std::vector<ListNode>(n)), size(n) {
        for (int i = 0; i < n; ++i) {
            list[i].data = i + 1;
        }
    }

    ListNode& operator[](int i) {
        return list[i];
    }

    const ListNode& operator[](int i) const {
        return list[i];
    }

    void AddArc(int a, int b) {
        int idx_a = a - 1, idx_b = b - 1;
        ArcNode *new_arc = new ArcNode(idx_b, list[idx_a].first_arc);
        list[idx_a].first_arc = new_arc;
    }

    std::vector<ListNode> list;
    int size;
};

class Solution {

public:

    int BFS(const AdjacencyList &l, int n) {
        std::queue<std::pair<int, int>> queue;
        std::vector<bool> visited(n, false);
        queue.emplace(0, 0);
        visited[0] = true;
        while (!queue.empty()) {
            std::pair<int, int> idx_step = queue.front();
            int idx = idx_step.first;
            int step = idx_step.second;
            queue.pop();

            if (idx == n - 1) {
                return step;
            }

            ArcNode *arc = l[idx].first_arc;
            while (arc) {
                if (!visited[arc->idx]) {
                    queue.emplace(arc->idx, step + 1);
                    visited[arc->idx] = true;
                }
                arc = arc->next;
            }
        }

        return -1;
    }
};

int main(int argc, char* argv[])
{

    int n = 0, m = 0;
    std::cin >> n >> m;

    AdjacencyList l(n);
    while (m--) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        l.AddArc(a, b);
    }

    Solution sol;
    std::cout << sol.BFS(l, n);
    
    return 0;
}
