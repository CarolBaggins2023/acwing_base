#include <deque>
#include <iostream>
#include <queue>
#include <vector>

class Solution {

public:

    bool Judge(int row, int col, const std::vector<std::vector<int>> &map, const std::vector<std::vector<int>> &dis) {
        if (row < 0 || row >= map.size() || col < 0 || col >=map[0].size()) {
            return false;
        }
        if (map[row][col] == 1) {
            return false;
        }
        if (dis[row][col] != -1) {
            return false;
        }
        return true;
    }

    int BFS (const std::vector<std::vector<int>> &map) {
        std::queue<std::vector<int>, std::deque<std::vector<int>>> que;
        std::vector<std::vector<int>> dis(map.size(), std::vector<int>(map[0].size(), -1));
        std::vector<std::vector<int>> steps{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        que.emplace(std::vector<int>{0, 0});
        dis[0][0] = 0;
        while (!que.empty()) {
            std::vector<int> cur = que.front();
            que.pop();

            for (std::vector<int> step : steps) {
                int new_row = cur[0] + step[0], new_col = cur[1] + step[1];
                if (Judge(new_row, new_col, map, dis)) {
                    que.emplace(std::vector<int>{new_row, new_col});
                    dis[new_row][new_col] = dis[cur[0]][cur[1]] + 1;
                }
            }
        }

        return dis[map.size() - 1][map[0].size() - 1];
    }
};

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::vector<int>> map(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> map[i][j];
        }
    }

    Solution sol;
    std::cout << sol.BFS(map);
    
    return 0;
}
