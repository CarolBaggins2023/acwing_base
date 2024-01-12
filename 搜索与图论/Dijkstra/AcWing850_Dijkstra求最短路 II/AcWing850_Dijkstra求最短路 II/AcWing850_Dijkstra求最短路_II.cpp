#include <iostream>
#include <queue>
#include <utility>
#include <vector>

constexpr int max_dis = 0x3f3f3f3f3f;

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

// 邻接链表对重边的判断并不好
class AdjacencyList {

public:

    AdjacencyList(int n) : l(std::vector<ListNode>(n)) {}

    void AddArc(int a, int b, int w) {
        ArcNode *new_arc = new ArcNode(b, w, l[a].first_arc);
        l[a].first_arc = new_arc;
    }
    
    int FindShortestPath(int begin, int end) {
        std::vector<int> dist(l.size(), max_dis);
        std::vector<bool> found(l.size(), false);
        dist[begin] = 0;

        // 在寻找距离最短点时运用堆数据结构
        // 注意，que中的元素，pair.first是距离，pair.second是下标，因为greater<>对pair的排序默认按照first
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
        que.emplace(0, 0);
        while (!que.empty()) {
            std::pair<int, int> dis_idx = que.top();
            que.pop();
            int idx = dis_idx.second;

            // 如果没有if (found[idx]) {continue;}，会导致
            // 即使重边中的最短路已经确定了一点与起点的最短路，并用这点进行其他点的优化
            // 重边中的其他路可能会再次用这点进行其他点的优化
            // 假如有(begin, end, weight): (0, 1, 1), (0, 1, 2), (1, 2, 1)
            // ({dis, idx}) 由{0, 0}得到{1, 1}, {2, 1} -> 全部进入que
            // 之后的while中，（如果没有if (found[idx]) {continue;}）found[1]会被两次设为true，与1相连的边可能会被两次加入que
            
            // 已经找到最短路径的边（包括重边）不需要再次判断
            if (found[idx]) {
                continue;
            }
            found[idx] = true;
            
            ArcNode *arc = l[idx].first_arc;
            while (arc) {
                if (!found[arc->idx] && (dist[arc->idx] > dist[idx] + arc->weight)) {
                    dist[arc->idx] = dist[idx] + arc->weight;
                    que.emplace(dist[arc->idx], arc->idx);
                }
                arc = arc->next;
            }
        }

        return (dist[end] == max_dis) ? -1 : dist[end];
    }

    std::vector<ListNode> l;
};

// class AdjacencyMatrix {
//
// public:
//
//     AdjacencyMatrix(int n) : m(std::vector<std::vector<int>>(n, std::vector<int>(n, 0x3f3f3f3f))) {
//         for (int i = 0; i < n; ++i) {
//             m[i][i] = 0;
//         }
//     }
//
//     void AddArc(int a, int b, int w) {
//         m[a][b] = w;
//     }
//
//     int FindShortestPath(int begin, int end) {
//         std::vector<int> dist(m[begin]);
//         std::vector<bool> found(m.size(), false);
//         found[begin] = true;
//         while (true) {
//             int min_idx = -1;
//             for (int i = 0; i < m.size(); ++i) {
//                 if (!found[i] && (min_idx == -1 || dist[i] < dist[min_idx])) {
//                     min_idx = i;
//                 }
//             }
//             if (min_idx == -1 || dist[min_idx] == 0x3f3f3f3f) {
//                 break;
//             }
//
//             found[min_idx] = true;
//             for (int i = 0; i < m.size(); ++i) {
//                 if (!found[i] && (dist[i] > dist[min_idx] + m[min_idx][i])) {
//                     dist[i] = dist[min_idx] + m[min_idx][i];
//                 }
//             }
//         }
//
//         return (dist[end] == 0x3f3f3f3f) ? -1 : dist[end];
//     }
//
// private:
//
//     std::vector<std::vector<int>> m;
// };

int main(int argc, char** argv) {
    int n = 0, m = 0;
    std::cin >> n >> m;

    // AdjacencyMatrix adj(n);
    AdjacencyList adj(n);
    while (m--) {
        int x = 0, y = 0, z = 0;
        std::cin >> x >> y >> z;
        adj.AddArc(x - 1, y - 1, z);
    }

    std::cout << adj.FindShortestPath(0, n - 1);

    return 0;
}