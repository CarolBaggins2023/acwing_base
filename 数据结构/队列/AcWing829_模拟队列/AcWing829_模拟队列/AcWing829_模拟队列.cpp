#include <deque>
#include <iostream>
#include <vector>

class Queue {
public:
    Queue() : data(std::deque<int>()) {}

    void Push(int x) {
        data.emplace_back(x);
    }

    void Pop() {
        data.pop_front();
    }

    bool Empty() {
        return data.empty();
    }

    int Query() {
        return data.front();
    }

    std::deque<int> data;
};

int main(int argc, char* argv[])
{
    int M = 0;
    Queue q;
    std::cin >> M;
    while (M--) {
        std::string op;
        std::cin >> op;
        if (op == "push") {
            int x = 0;
            std::cin >> x;
            q.Push(x);
        } else if (op == "pop") {
            q.Pop();
        } else if (op == "empty") {
            std::cout << (q.Empty() ? "YES" : "NO") << std::endl;
        } else if (op == "query") {
            std::cout << q.Query() << std::endl;
        }
    }
    
    return 0;
}
