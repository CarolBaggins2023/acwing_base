#include <iostream>
#include <queue>
#include <vector>

class ArcNode {

public:

    ArcNode(int _to, ArcNode *_next) : to(_to), next(_next) {}

    int to;
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

    ListNode& operator[](int i) {
        return l[i];
    }

    void AddArc(int u, int v) {
        ArcNode *arc = new ArcNode(v, l[u].first_arc);
        l[u].first_arc = arc;
    }
    
    std::vector<ListNode> l;
};

class Solution {

public:

    bool JudgeBipartiteGraph(int n, int m, AdjacencyList al) {
        std::vector<int> color(n, 0);

        // 可能存在多个连通图，所以要遍历所有顶点
        for (int i = 0; i < n; ++i) {
            if (color[i] != 0) {
                continue;
            }

            std::queue<int> que;
            que.emplace(i);
            // 因为是在一个新的连通图中，所以染色的值可以任取
            color[i] = 1;

            while (!que.empty()) {
                int vertex = que.front();
                que.pop();

                ArcNode *arc = al[vertex].first_arc;
                while (arc) {
                    int to = arc->to;
                    // else if 中不能排除自环，自环也会破坏二分图
                    if (color[to] == 0) {
                        color[to] = 3 - color[vertex];
                        que.emplace(to);
                    } else if (color[to] == color[vertex]) {
                        return false;
                    }
                
                    arc = arc->next;
                }
            }
        }
        
        
        bool flag = true;
        for (int i = 0; i < color.size(); ++i){
            if (color[i] == 0) {
                flag = false;
            }
        }
        return flag;
    }
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::cin >> n >> m;

    AdjacencyList al(n);
    for (int i = 0; i < m; ++i) {
        int u = 0, v = 0;
        std::cin >> u >> v;
        al.AddArc(u - 1, v - 1);
        al.AddArc(v - 1, u - 1);
    }

    Solution sol;
    std::cout << (sol.JudgeBipartiteGraph(n, m, al) ? "Yes" : "No");
    
    return 0;
}
