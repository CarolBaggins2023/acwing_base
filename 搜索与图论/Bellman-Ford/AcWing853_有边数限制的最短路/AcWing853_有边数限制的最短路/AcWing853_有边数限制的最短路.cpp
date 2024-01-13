#include <iostream>
#include <vector>

class Edge {

public:

    Edge(int _from, int _to, int _weight) : from(_from), to(_to), weight(_weight) {}

    int from;
    int to;
    int weight;
};

class Solution {

public:

    int FindShortestPath(int n, const std::vector<Edge> &edges, int start, int end, int k) {
        std::vector<int> dist(n, 0x3f3f3f3f);
        dist[start] = 0;

        for (int i = 0; i < k; ++i) {
            // 在松弛时，不能用最新的dist
            // 因为本题对边数有要求，而用最新的dist[edge.from]去更新dist[edge.to]，看上去只用了一条边，
            // 但实际上dist[edge.from]可能刚被用一条边松弛过了，相当于dist[edge.to]实际上用了两条边
            std::vector<int> backup(dist);
            for (const Edge &edge : edges) {
                dist[edge.to] = std::min(dist[edge.to], backup[edge.from] + edge.weight);
            }
        }

        // 由于本题本身就有边数限制，所以不用考虑负权回路的情况

        return dist[end];
    }
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0, k = 0;
    std::cin >> n >> m >> k;

    std::vector<Edge> edges;
    while (m--) {
        int x = 0, y = 0, z = 0;
        std::cin >> x >> y >> z;
        edges.emplace_back(x - 1, y - 1, z);
    }

    Solution sol;
    int res = sol.FindShortestPath(n, edges, 0, n - 1, k);
    if (res < 0x3f3f3f3f / 2) {
        std::cout << res;
    } else {
        std::cout << "impossible";
    }
    
    return 0;
}
