#include <iostream>
#include <string>
#include <vector>

int FindRoot(std::vector<int> &parent, int x) {
    if (x != parent[x]) {
        int root_x = FindRoot(parent, parent[x]);
        parent[x] = root_x;
    }
    return parent[x];
}

void Merge(std::vector<int> &parent, int a, int b) {
    int root_a = FindRoot(parent, a), root_b = FindRoot(parent, b);
    parent[root_b] = root_a;
}

int main(int argc, char* argv[])
{
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<int> parent(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    while (m--) {
        std::string op;
        int a = 0, b = 0;
        std::cin >> op >> a >> b;
        if (op == "M") {
            Merge(parent, a, b);
        } else {
            int root_a = FindRoot(parent, a), root_b = FindRoot(parent, b);
            std::cout << ((root_a == root_b) ? "Yes" : "No") << std::endl;
        }
    }
    
    return 0;
}
