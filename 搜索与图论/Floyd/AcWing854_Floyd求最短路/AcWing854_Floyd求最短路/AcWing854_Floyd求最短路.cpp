#include <iostream>
#include <vector>

class AdjacencyMatrix {

public:

    AdjacencyMatrix(int n) : m(std::vector<std::vector<int>> (n, std::vector<int>(n, 0x3f3f3f3f))) {
        for (int i = 0; i < n; ++i) {
            m[i][i] = 0;
        }
    }

    void AddArc(int a, int b, int w) {
        m[a][b] = std::min(m[a][b], w);
    }

    std::vector<std::vector<int>> m;
};

class Solution {

public:

    Solution(const AdjacencyMatrix &am) : short_path(am.m) {}

    void FindShortestPath() {
        int n = short_path.size();
        // 注意，对中间节点的遍历应该在最外层，否则在i到j的最优路径上，只会有一个中间节点
        // 而且，中间节点可以以任意顺序遍历，具体可参考：https://blog.csdn.net/zhongkeli/article/details/8832946
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    // 注意，这里用动态规划理解的话，状态转移矩阵应该是三层的 short_path[k][i][j]
                    // 表示，以节点0~k为中间节点，节点i和节点j之间的最短距离
                    // 状态转移方程式 short_path[k][i][j] = min(short_path[k - 1][i][j], short_path[k - 1][i][k] + short_path[k - 1][k][j])
                    // 因为计算 short_path[k][i][j]只需要 short_path[k - 1][i][j]，所以不用保存 k-1 层之前的内容，
                    // 从而在循环中可以简化为两层的 short_path[i][j]
                    // 综上所述，下面这行代码不应该被理解为，“以节点k为中间节点，优化节点i和节点j之间的最短距离”
                    // 而是，“在节点0~k-1的基础上，以节点k为中间节点，优化节点i和节点j之间的最短距离”
                    short_path[i][j] = std::min(short_path[i][j], short_path[i][k] + short_path[k][j]);
                }
            }
        }
    }

    std::vector<std::vector<int>> short_path;
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0, k = 0;
    std::cin >> n >> m >> k;

    AdjacencyMatrix am(n);
    while (m--) {
        int x = 0, y = 0, z = 0;
        std::cin >> x >> y >> z;
        am.AddArc(x - 1, y - 1, z);
    }

    Solution sol(am);
    sol.FindShortestPath();

    while (k--) {
        int x = 0, y = 0;
        std::cin >> x >> y;
        int res = sol.short_path[x - 1][y - 1];
        if (res >= 0x3f3f3f3f / 2) {
            std::cout << "impossible" << std::endl;
        } else {
            std::cout << res << std::endl;
        }
    }
    
    return 0;
}
