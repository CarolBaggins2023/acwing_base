#include <iostream>
#include <vector>

class AdjacencyMatrix {

public:

    AdjacencyMatrix(int n) : m(std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1, 0x3f3f3f3f))) {}

    void AddArc(int a, int b, int w) {
        m[a][b] = std::min(m[a][b], w);
    }

    int FindShortPath(int n) {
        // 下标为0的元素无效
        std::vector<bool> has_find(n + 1, false);
        int find_cnt = 1;
        std::vector<int> dist(m[1]);
        has_find[1] = true;
        while (find_cnt < n) {
            int min_idx = 0;
            for (int i = 1; i < dist.size(); ++i) {
                if (!has_find[i] && (min_idx == 0 || dist[i] < dist[min_idx])) {
                    min_idx = i;
                }
            }
            has_find[min_idx] = true;
            ++find_cnt;

            for (int i = 1; i < dist.size(); ++i) {
                if (!has_find[i] && dist[i] > dist[min_idx] + m[min_idx][i]) {
                    dist[i] = dist[min_idx] + m[min_idx][i];
                }
            }
        }
        
        return (dist[n] == 0x3f3f3f3f) ? -1 : dist[n];
    }

    std::vector<std::vector<int>> m;
};

int main(int argc, char* argv[])
{

    int n = 0, m = 0;
    std::cin >> n >> m;

    AdjacencyMatrix matrix(n);
    while (m--) {
        int a = 0, b = 0, w = 0;
        std::cin >> a >> b >> w;
        matrix.AddArc(a, b, w);
    }

    std::cout << matrix.FindShortPath(n);
    
    return 0;
}
