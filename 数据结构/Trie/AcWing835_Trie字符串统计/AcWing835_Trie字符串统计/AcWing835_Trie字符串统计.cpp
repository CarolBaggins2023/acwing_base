#include <iostream>
#include <vector>

class TrieNode {
public:
    TrieNode() : data('\0'), has_word(0), child(nullptr), sib(nullptr) {}
    TrieNode(char _data) : data(_data), has_word(0), child(nullptr), sib(nullptr) {}

    char data;
    int has_word;
    TrieNode *child;
    TrieNode *sib;
};

class TrieTree {
public:
    TrieTree() : root(new TrieNode()) {}

    TrieNode* FindChild(TrieNode *node, char c) {
        TrieNode *child = node->child;
        while (child != nullptr && child->data != c) {
            child = child->sib;
        }
        return child;
    }
    
    void Insert(const std::string &s) {
        TrieNode *node = root;
        for (int i = 0; i < s.size(); ++i) {
            TrieNode *child = FindChild(node, s[i]);
            if (child) {
                node = child;
            } else {
                TrieNode *new_node = new TrieNode(s[i]);
                new_node->sib = node->child;
                node->child = new_node;
                node = new_node;
            }
        }
        ++(node->has_word);
    }

    int Query(const std::string &s) {
        TrieNode *node = root;
        for (int i = 0; i < s.size(); ++i) {
            TrieNode *child = FindChild(node, s[i]);
            if (child) {
                node = child;
            } else {
                return 0;
            }
        }
        return node->has_word;
    }

    TrieNode *root;
};

int main(int argc, char* argv[])
{
    TrieTree *t = new TrieTree();
    
    int N = 0;
    std::cin >> N;
    while (N--) {
        char op = '\0';
        std::string x;
        std::cin >> op >> x;
        if (op == 'I') {
            t->Insert(x);
        } else {
            std::cout << t->Query(x) << std::endl;
        }
    }
    
    return 0;
}
