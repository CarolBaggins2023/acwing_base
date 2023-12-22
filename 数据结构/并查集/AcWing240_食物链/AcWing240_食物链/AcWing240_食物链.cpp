#include <iostream>
#include <string>
#include <vector>

int FindRoot(std::vector<int> &parent, std::vector<int> &dis, int x) {
    if (x != parent[x]) {
        int old_parent = parent[x];
        parent[x] = FindRoot(parent, dis, parent[x]);
        dis[x] += dis[old_parent];
    }
    return parent[x];
}

void Merge(std::vector<int> &parent, std::vector<int> &dis, int x, int y, int root_x, int root_y, int flag) {
    if (flag == 0) {
        parent[root_y] = root_x;
        // (dis[x]) % 3 == (dis[y] + dis[root_y]) % 3
        dis[root_y] = (dis[x] - dis[y] + 3) % 3;
    } else {
        parent[root_y] = root_x;
        // (dis[x]) % 3 == (dis[y] + dis[root_y] + 1) % 3
        dis[root_y] = (dis[x] - dis[y] - 1 + 3) % 3;
    }
}

int main(int argc, char* argv[])
{
    int n = 0, k = 0;
    std::cin >> n >> k;

    int res = 0;
    std::vector<int> parent(n + 1, 0);
    std::vector<int> dis(n + 1, 0);
    for (int i = 1; i < parent.size(); ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < k; ++i) {
        int d = 0, x = 0, y = 0;
        std::cin >> d >> x >> y;
        
        if (x > n || y > n) {
            ++res;
            // std::cout << i << " is false" << std::endl;
            continue;
        }

        int root_x = FindRoot(parent, dis, x), root_y = FindRoot(parent, dis, y);
        if (d == 1) {
            if (root_x == root_y) {
                // (dis[x] % 3) != (dis[y] % 3), wrong
                if ((dis[x] - dis[y]) % 3 != 0) {
                    ++res;
                    // if (((dis[x] - dis[y]) % 3 != 0) != ((dis[x] % 3) != (dis[y] % 3))) {
                    //     std::cout << dis[x] << " " << dis[y] << std::endl;
                    // }
                    // std::cout << i << " is false" << std::endl;
                }
            } else {
                Merge(parent, dis, x, y, root_x, root_y, 0);
            }
        } else {
            if (root_x == root_y) {
                // (dis[x] % 3) != ((dis[y] + 1) % 3), wrong
                if ((dis[x] - dis[y] - 1) % 3 != 0) {
                    ++res;
                    // if (((dis[x] - dis[y] - 1) % 3 != 0) != ((dis[x] % 3) != ((dis[y] + 1) % 3))) {
                    //     std::cout << dis[x] << " " << dis[y] << std::endl;
                    // }
                    // std::cout << i << " is false" << std::endl;
                }
            } else {
                Merge(parent, dis, x, y, root_x, root_y, 1);
            }
        }
    }

    std::cout << res;
    
    return 0;
}
