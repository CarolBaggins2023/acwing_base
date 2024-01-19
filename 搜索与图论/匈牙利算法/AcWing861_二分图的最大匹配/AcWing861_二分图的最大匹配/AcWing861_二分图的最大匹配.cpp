#include <iostream>
#include <vector>

class AdjacencyMatrix {

public:

    AdjacencyMatrix(int n1, int n2) : am(std::vector<std::vector<bool>>(n1, std::vector<bool>(n2, false))) {}

    void AddEdge(int u, int v) {
        am[u][v] = true;
    }

    const std::vector<bool>& operator[](int i) const {
        return am[i];
    }

    std::vector<std::vector<bool>> am;

    const int max_int = 0x3f3f3f3f;
};

class Solution {

public:

    bool CanFind(int node, int n2, const AdjacencyMatrix &am, std::vector<int> &match, std::vector<bool> &visited) {
        for (int i = 0; i < n2; ++i) {
            // 节点i目前不在增广路上
            if (!am[node][i] || visited[i]) {
                continue;
            }

            // 将节点i加入增广路
            // 即使if中的条件为false，visited[i]也不用更改
            // 因为if中的条件为false说明match[i]或者之后的点无法找到增广路，那么之后就不用考虑i了
            visited[i] = true;
            // 节点i是未覆盖点 或 节点i的原匹配点能再找到一条增广路
            if (match[i] == -1 || CanFind(match[i], n2, am, match, visited)) {
                match[i] = node;
                return true;
            }
        }

        return false;
    }

    int FindMatch(int n1, int n2, AdjacencyMatrix am) {
        int res = 0;
        std::vector<int> match(n2, -1);
        for (int i = 0; i < n1; ++i) {
            std::vector<bool> visited(n2, false);
            // 加入节点i后，能否找到一条增广路
            if (CanFind(i, n2, am, match, visited)) {
                ++res;
            }
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    int n1 = 0, n2 = 0, m = 0;
    std::cin >> n1 >> n2 >> m;

    AdjacencyMatrix am(n1, n2);
    while (m--) {
        int u = 0, v = 0;
        std::cin >> u >> v;
        am.AddEdge(u - 1, v - 1);
    }

    Solution sol;
    std::cout << sol.FindMatch(n1, n2, am);
    
    return 0;
}
