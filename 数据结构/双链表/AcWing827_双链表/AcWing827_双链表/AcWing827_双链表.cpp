#include <iostream>
#include <string>

class ListNode {
public:
    ListNode(int _idx, int _data, ListNode *_pre, ListNode *_next) : idx(_idx), data(_data), pre(_pre), next(_next) {}
    
    int idx;
    int data;
    ListNode *pre;
    ListNode *next;
};

class List {
public:
    List() : head(new ListNode(0, 0, nullptr, nullptr)) {}

    void OperationL(int idx, int x) {
        ListNode *new_node = new ListNode(idx, x, head, head->next);
        ListNode *first_node = head->next;
        if (first_node) {
            first_node->pre = new_node;
        }
        head->next = new_node;
    }

    void OperationR(int idx, int x) {
        ListNode *last_node = head;
        while (last_node->next) {
            last_node = last_node->next;
        }
        ListNode *new_node = new ListNode(idx, x, last_node, nullptr);
        last_node->next = new_node;
    }

    void OperationD(int k) {
        ListNode *kth_node = GetKthNode(k);
        ListNode *pre_node = kth_node->pre;
        ListNode *next_node = kth_node->next;
        pre_node->next = next_node;
        if (next_node) {
            next_node->pre = pre_node;
        }
        delete kth_node;
    }

    void OperationIL(int k, int idx, int x) {
        ListNode *kth_node = GetKthNode(k);
        ListNode *pre_node = kth_node->pre;
        ListNode *new_node = new ListNode(idx, x, pre_node, kth_node);
        pre_node->next = new_node;
        kth_node->pre = new_node;
    }

    void OperationIR(int k, int idx, int x) {
        ListNode *kth_node = GetKthNode(k);
        ListNode *next_node = kth_node->next;
        ListNode *new_node = new ListNode(idx, x, kth_node, next_node);
        kth_node->next = new_node;
        if (next_node) {
            next_node->pre = new_node;
        }
    }

    ListNode *GetKthNode(int k) {
        ListNode *node = head;
        while (node->idx != k) {
            node = node->next;
        }
        return node;
    }

    void Print() {
        ListNode *node = head->next;
        while (node) {
            std::cout << node->data << " ";
            node = node->next;
        }
    }
    
    ListNode *head;
};

int main(int argc, char* argv[])
{
    int M = 0, idx = 1;
    List l;
    std::cin >> M;
    while (M--) {
        std::string op;
        std::cin >> op;
        if (op == "L") {
            int x = 0;
            std::cin >> x;
            l.OperationL(idx++, x);
        } else if (op == "R") {
            int x = 0;
            std::cin >> x;
            l.OperationR(idx++, x);
        } else if (op == "D") {
            int k = 0;
            std::cin >> k;
            l.OperationD(k);
        } else if (op == "IL") {
            int k = 0, x = 0;
            std::cin >> k >> x;
            l.OperationIL(k, idx++, x);
        } else if (op == "IR") {
            int k = 0, x = 0;
            std::cin >> k >> x;
            l.OperationIR(k, idx++, x);
        }
    }

    l.Print();
    
    return 0;
}
