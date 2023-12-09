#include <deque>
#include <iostream>
#include <string>

class Stack {
public:
    Stack() : dq(std::deque<int>()) {}

    void Push(int x) {
        dq.emplace_back(x);
    }

    void Pop() {
        dq.pop_back();
    }

    bool Empty() {
        return dq.empty();
    }

    int Query() {
        return dq.back();
    }

    std::deque<int> dq;
};

int main(int argc, char* argv[])
{
    int M = 0;
    scanf_s("%d", &M);

    Stack s;
    while (M--) {
        std::string op;
        std::cin >> op;
        if (op == "push") {
            int x = 0;
            std::cin >> x;
            s.Push(x);
        } else if (op == "pop") {
            s.Pop();
        } else if (op == "empty") {
            std::cout << (s.Empty() ? "YES" : "NO") << std::endl;
        } else if (op == "query") {
            std::cout << s.Query() << std::endl;
        } else {
            std::cout << "Wrong";
            return 0;
        }
    }
    
    return 0;
}
