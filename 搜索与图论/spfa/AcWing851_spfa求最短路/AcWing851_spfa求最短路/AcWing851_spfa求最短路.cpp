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

    int FindShortestPath_SPFA(int n, int start, int end, const AdjacencyList &l) {
        std::vector<int> dist(n, 0x3f3f3f3f);
        std::queue<int> que;
        // 记录哪些点已经在队列中
        // 假如当前队列为 {A, B, 1, C, D}，点A松弛了点1，那么不需要将点1加入队列
        // 因为点1已经在队列中，而且等到处理点1时，使用的是已经被点A松弛过的数值
        std::vector<int> in_queue(n, false);
        dist[start] = 0;
        que.emplace(start);
        in_queue[0] = true;
        while (!que.empty()) {
            int vertex = que.front();
            que.pop();
            in_queue[vertex] = false;

            ArcNode *arc = l[vertex].first_arc;
            while (arc) {
                if (dist[arc->idx] > dist[vertex] + arc->weight) {
                    dist[arc->idx] = dist[vertex] + arc->weight;
                    if (!in_queue[arc->idx]) {
                        que.emplace(arc->idx);
                        in_queue[arc->idx] = true;
                    }
                }
                arc = arc->next;
            }
        }

        return dist[end];
    }

    // BellmanFord太慢
    int FindShortestPath_BellmanFord(int n, int start, int end, const std::vector<Edge> &edges) {
        std::vector<int> dist(n, 0x3f3f3f3f);
        dist[start] = 0;

        for (int i = 0; i < n - 1; ++i) {
            // 一个小优化，如果某一轮没有边得到松弛，说明松弛已经结束
            bool flag = false;
            for (const Edge &edge : edges) {
                int from = edge.from, to = edge.to, weight = edge.weight;
                if (dist[to] > dist[from] + weight) {
                    dist[to] = dist[from] + weight;
                    flag = true;
                }
            }
            if (!flag) {
                break;
            }
        }

        // 题目保证不会产生负权回路

        return dist[end];
    }
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::cin >> n >> m;

    // std::vector<Edge> edges;
    AdjacencyList l(n);
    while (m--) {
        int x = 0, y = 0, z = 0;
        std::cin >> x >> y >> z;
        // edges.emplace_back(x - 1, y - 1, z);
        l.AddArc(x - 1, y - 1, z);
    }

    Solution sol;
    // int res = sol.FindShortestPath_BellmanFord(n, 0, n - 1, edges);
    int res = sol.FindShortestPath_SPFA(n, 0, n - 1, l);
    if (res == 0x3f3f3f3f) {
        std::cout << "impossible";
    } else {
        std::cout << res;
    }
    
    return 0;
}
