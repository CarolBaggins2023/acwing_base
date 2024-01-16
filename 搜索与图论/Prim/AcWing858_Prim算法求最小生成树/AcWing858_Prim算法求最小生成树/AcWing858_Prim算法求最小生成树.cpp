#include <iostream>
#include <vector>

class AdjacencyMatrix {

public:

    AdjacencyMatrix(int n) : m(std::vector<std::vector<int>> (n, std::vector<int> (n, 0x3f3f3f3f))) {
        for (int i = 0; i < n; ++i) {
            m[i][i] = 0;
        }
    }

    void AddArc(int u, int v, int w) {
        int min_w = std::min(m[u][v], w);
        m[v][u] = m[u][v] = min_w;
    }

    std::vector<std::vector<int>> m;
};

class Solution {

public:

    int GetMiniumSpanningTree(const AdjacencyMatrix &am, bool &flag) {
        int n = am.m.size();
        std::vector<bool> state(n, false);
        std::vector<int> dist(n, 0x3f3f3f3f);
        std::vector<int> pre(n, -1);
        dist[0] = 0;
        // 要将n个节点加入生成树
        for (int i = 0; i < n; ++i) {
            int min_idx = -1;
            for (int j = 0; j < n; ++j) {
                if (!state[j] && (min_idx == -1 || dist[j] < dist[min_idx])) {
                    min_idx = j;
                }
            }

            if (dist[min_idx] == 0x3f3f3f3f) {
                std::cout << "impossible";
                flag = false;
                return -1;
            }

            state[min_idx] = true;
            for (int j = 0; j < n; ++j) {
                // 节点j到目前的生成树的距离，不是 dist[min_idx] + am.m[min_idx][j]，而是 am.m[min_idx][j]
                // 因为现在min_idx已经在生成树中了，所以dist[min_idx]应该视为0
                if (!state[j] && (am.m[min_idx][j] < dist[j])) {
                    dist[j] = am.m[min_idx][j];
                    pre[j] = min_idx;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (pre[i] == -1) {
                continue;
            }
            sum += am.m[i][pre[i]];
        }
        return sum;
    }
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::cin >> n >> m;

    AdjacencyMatrix am(n);
    while (m--) {
        int u = 0, v = 0, w = 0;
        std::cin >> u >> v >> w;
        am.AddArc(u - 1, v - 1, w);
    }

    Solution sol;
    bool flag = true;
    int res = sol.GetMiniumSpanningTree(am, flag);
    if (flag) {
        std::cout << res;
    }
    
    return 0;
}
