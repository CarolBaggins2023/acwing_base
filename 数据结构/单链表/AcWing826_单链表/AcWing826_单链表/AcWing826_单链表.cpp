#include <iostream>
#include <vector>

class ListNode {
public:
    ListNode(int _idx, int _data, ListNode *_next) : idx(_idx), data(_data), next(_next) {}

    int idx;
    int data;
    ListNode *next;
};

class List {
public:
    List() : head(new ListNode(0, 0, nullptr)) {}
    
    void OperationH(int idx, int x) {
        // 向链表头插入一个数 x
        ListNode *new_node = new ListNode(idx, x, head->next);
        head->next = new_node;
    }

    void OperationD(int k) {
        // 删除第 k 个插入的数后面的数（当 k 为 0 时，表示删除头结点）
        if (k == 0) {
            ListNode *node = head->next;
            if (node) {
                head->next = node->next;
                delete node;
            }
        } else {
            ListNode *kth_node = GetNode(k);
            ListNode *next_node = kth_node->next;
            if (next_node) {
                kth_node->next = next_node->next;
                delete next_node;
            }
        }
    }

    void OperationI(int k, int idx, int x) {
        // 在第 k 个插入的数后面插入一个数 x（此操作中 k 均大于 0）
        ListNode *kth_node = GetNode(k);
        ListNode *new_node = new ListNode(idx, x, kth_node->next);
        kth_node->next = new_node;
    }

    ListNode* GetNode(int k) {
        ListNode *node = head;
        while (node && node->idx != k) {
            node = node->next;
        }
        return node;
    }

    void PrintList() {
        ListNode *node = head->next;
        while (node) {
            printf("%d ", node->data);
            node = node->next;
        }
    }
    
    ListNode *head;
};

int main(int argc, char* argv[])
{
    int M = 0;
    List l;
    scanf_s("%d", &M);

    int idx = 1;
    while (M--) {
        char op;
        std::cin >> op;
        if (op == 'H') {
            int x = 0;
            scanf_s("%d", &x);
            l.OperationH(idx++, x);
        } else if (op == 'D') {
            int k = 0;
            scanf_s("%d", &k);
            l.OperationD(k);
        } else if (op == 'I') {
            int k = 0, x = 0;
            scanf_s("%d %d", &k, &x);
            l.OperationI(k, idx++, x);
        }
    }

    l.PrintList();
    
    return 0;
}
