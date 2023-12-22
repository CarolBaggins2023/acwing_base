#include <iostream>
#include <string>
#include <vector>

int FindRoot(std::vector<int> &parent, int x) {
    if (x != parent[x]) {
        int root = FindRoot(parent, parent[x]);
        parent[x] = root;
    }
    return parent[x];
}

void Merge(std::vector<int> &parent, int a, int b, std::vector<int> &size) {
    int root_a = FindRoot(parent, a), root_b = FindRoot(parent, b);
    // 如果a和b已经在同一个集合中，size就不应该变化
    // parent的修改放在if内外都可以
    if (root_a != root_b) {
        parent[root_b] = root_a;
        size[root_a] += size[root_b];
    }
}

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<int> parent(n + 1);
    std::vector<int> size(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    while (m--) {
        std::string op;
        std::cin >> op;
        if (op == "C") {
            int a = 0, b = 0;
            std::cin >> a >> b;
            Merge(parent, a, b, size);
        } else if (op == "Q1") {
            int a = 0, b = 0;
            std::cin >> a >> b;
            int root_a = FindRoot(parent, a), root_b = FindRoot(parent, b);
            std::cout << ((root_a == root_b) ? "Yes" : "No") << std::endl;
        } else {
            int a = 0;
            std::cin >> a;
            std::cout << size[FindRoot(parent, a)] << std::endl;
        }
    }
    
    return 0;
}
