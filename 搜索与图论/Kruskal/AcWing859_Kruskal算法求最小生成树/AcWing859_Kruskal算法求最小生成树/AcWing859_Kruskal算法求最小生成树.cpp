#include <algorithm>
#include <iostream>
#include <vector>

class Edge {

public:

    Edge(int _from, int _to, int _weight) : from(_from), to(_to), weight(_weight) {}

    bool operator<(const Edge &rhs) const {
        return weight < rhs.weight;
    }

    int from;
    int to;
    int weight;
};

class UnionFindSet {

public:

    UnionFindSet(int n) : parent(std::vector<int>(n)), rank(std::vector<int>(n, 0)) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int Find(int x) {
        if (parent[x] == x) {
            return x;
        }
        
        parent[x] = Find(parent[x]);
        return parent[x];
    }

    bool Union(int x, int y) {
        int root_x = Find(x), root_y = Find(y);
        if (root_x == root_y) {
            return false;
        }

        if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
            ++rank[root_y];
        } else {
            parent[root_y] = root_x;
            ++rank[root_x];
        }
        return true;
    }

    std::vector<int> parent;
    std::vector<int> rank;
};

class Solution {

public:

    int MinimumSpanningTree(int n, std::vector<Edge> edges, bool &flag) {
        std::sort(edges.begin(), edges.end(), std::less<>());

        int sum = 0;
        int edge_cnt = 0;
        UnionFindSet ufs(n);
        for (Edge edge : edges) {
            if(ufs.Union(edge.from, edge.to)) {
                sum += edge.weight;
                ++edge_cnt;
            }
            if (edge_cnt == n - 1) {
                flag = true;
                return sum;
            }
        }

        return sum;
    }
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<Edge> edges;
    while (m--) {
        int u = 0, v = 0, w = 0;
        std::cin >> u >> v >> w;
        edges.emplace_back(u - 1, v - 1, w);
    }

    Solution sol;
    bool flag = false;
    int res = sol.MinimumSpanningTree(n, edges, flag);
    if (flag) {
        std::cout << res;
    } else {
        std::cout << "impossible";
    }
    
    return 0;
}
