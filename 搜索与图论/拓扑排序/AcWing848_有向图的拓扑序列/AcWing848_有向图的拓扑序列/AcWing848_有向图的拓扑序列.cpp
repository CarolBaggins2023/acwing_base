#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <vector>

class ArcNode {

public:

    ArcNode(int _idx, ArcNode *_next) : idx(_idx), next(_next) {}

    int idx;
    ArcNode *next;
};

class ListNode {

public:

    ListNode() : data(-1), indegree(0), first_arc(nullptr) {}

    int data;
    int indegree;
    ArcNode *first_arc;
};

class AdjacencyList {

public:

    AdjacencyList(int n) : l(std::vector<ListNode>(n)) {
        for (int i = 0; i < n; ++i) {
            l[i].data = i + 1;
        }
    }

    const ListNode& operator[](int idx) const {
        return l[idx];
    }

    void AddArc(int a, int b) {
        int idx_a = a - 1, idx_b = b - 1;
        ArcNode *new_node = new ArcNode(idx_b, l[idx_a].first_arc);
        l[idx_a].first_arc = new_node;
        ++l[idx_b].indegree;
    }

    int size() const {
        return l.size();
    }

    std::vector<ListNode> l;
};

class Solution {

public:

    void GetTopoOrder(const AdjacencyList &al, int n) {
        std::vector<int> res;
        std::queue<int, std::deque<int>> que;
        std::vector<int> indegree(n, -1);
        for (int i = 0; i < al.size(); ++i) {
            indegree[i] = al[i].indegree;
            if (indegree[i] == 0) {
                que.emplace(i);
            }
        }

        while (!que.empty()) {
            int idx = que.front();
            que.pop();
            res.emplace_back(al[idx].data);

            ArcNode *arc = al[idx].first_arc;
            while (arc) {
                --indegree[arc->idx];
                if (indegree[arc->idx] == 0) {
                    que.emplace(arc->idx);
                }
                arc = arc->next;
            }
        }

        for (int i : indegree) {
            if (i != 0) {
                std::cout << -1;
                return;
            }
        }

        for (int i : res) {
            std::cout << i << " ";
        }
    }
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::cin >> n >> m;

    AdjacencyList al(n);
    while (m--) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        al.AddArc(a, b);
    }

    Solution sol;
    sol.GetTopoOrder(al, n);
    
    return 0;
}
