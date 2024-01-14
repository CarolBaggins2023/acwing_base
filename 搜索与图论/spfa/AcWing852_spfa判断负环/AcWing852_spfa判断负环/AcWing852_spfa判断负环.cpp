#include <iostream>
#include <queue>
#include <vector>

class ArcNode {

public:

    ArcNode(int _idx, int _weight, ArcNode *_next) : idx(_idx), weight(_weight), next(_next) {}

    int idx;
    int weight;
    ArcNode *next;
};

class ListNode {

public:

    ListNode() : first_arc(nullptr) {}

    ArcNode *first_arc;
};

class AdjacencyList {

public:

    AdjacencyList(int n) : l(std::vector<ListNode>(n)) {}

    void AddArc(int a, int b, int w) {
        ArcNode *new_arc = new ArcNode(b, w, l[a].first_arc);
        l[a].first_arc = new_arc;
    }

    const ListNode& operator[](int i) const {
        return l[i];
    }
    
    std::vector<ListNode> l;
};

class Edge {

public:

    Edge(int _from, int _to, int _weight) : from(_from), to(_to), weight(_weight) {}

    int from;
    int to;
    int weight;
};

class Solution {

public:

    int JudgeNegativeRing(int n, const AdjacencyList &l) {
        // 以所有节点为起点，做一次spfa是正确的，但是效率太低
        // 使用加入虚拟节点的技巧：
        // 在图中加入一个虚拟节点，该节点有n条指向原图中节点的边，长度为0
        // 若原图有负环，则加入虚拟节点后的新图也有负环 --> 可以加入虚拟节点的依据
        // 将虚拟节点加入队列之后，执行第一次循环，所有节点都会得到更新
        // 对于其他节点，dist = 0，且加入队列
        // 因此在初始化中: (1)dist(n, 0)，(2)所有节点加入队列
        
        std::vector<int> dist(n, 0);
        std::queue<int> que;
        std::vector<int> in_queue(n, true);
        std::vector<int> arc_cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            que.emplace(i);
        }
        
        while (!que.empty()) {
            int vertex = que.front();
            que.pop();
            in_queue[vertex] = false;

            ArcNode *arc = l[vertex].first_arc;
            while (arc) {
                if (dist[arc->idx] > dist[vertex] + arc->weight) {
                    dist[arc->idx] = dist[vertex] + arc->weight;
                    arc_cnt[arc->idx] = arc_cnt[vertex] + 1;
                    
                    if (arc_cnt[arc->idx] >= n) {
                        return true;
                    }
                    
                    if (!in_queue[arc->idx]) {
                        que.emplace(arc->idx);
                        in_queue[arc->idx] = true;
                    }
                }
                arc = arc->next;
            }
        }

        return false;
    }
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    
    AdjacencyList l(n);
    while (m--) {
        int x = 0, y = 0, z = 0;
        std::cin >> x >> y >> z;
        l.AddArc(x - 1, y - 1, z);
    }

    Solution sol;
    bool res = sol.JudgeNegativeRing(n, l);
    if (res) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
    
    return 0;
}
