#include <iostream>

class BitTree {
private:
    struct Node {
        int data;
        Node *lChild, *rChild;
    } *root, *p;

public:
    BitTree() {
        root = p = new Node{0, nullptr, nullptr};
    }

    Node *getRoot() {
        return root;
    }

    void add(Node *node, int data, bool right = false) {
        if (!right)
            node->lChild = new Node{data, nullptr, nullptr};
        else
            node->rChild = new Node{data, nullptr, nullptr};
    }

    void preOrder(Node *node) {
        if (node != nullptr) {
            printf("%d\n", node->data);
            preOrder(node->lChild);
            preOrder(node->rChild);
        }
    }

    void inOrder(Node *node) {
        if (node != nullptr) {
            inOrder(node->lChild);
            printf("%d\n", node->data);
            inOrder(node->rChild);
        }
    }

    void postOrder(Node *node) {
        if (node != nullptr) {
            postOrder(node->lChild);
            postOrder(node->rChild);
            printf("%d\n", node->data);
        }
    }
};
