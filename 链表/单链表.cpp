#include <iostream>

class LinkList {
private:
    int d;

    struct Node {
        int data;
        Node *next;
    } *head, *tail, *p;

public:
    void print() {
        p = head;
        while (p != nullptr) {
            printf("%d\n", p->data);
            p = p->next;
        }
    }

    // 头插法，带头结点
    void headInsert() {
        head = new Node{0, nullptr};
        while (scanf("%d", &d))
            head->next = new Node{d, head->next};
    }

    // 头插法，无头结点
    void headInsert2() {
        head = new Node{0, nullptr};
        while (scanf("%d", &d))
            head = new Node{d, head};
    }

    //尾插法
    void tailInsert() {
        head = tail = new Node{0, nullptr};
        while (scanf("%d", &d))
            tail = tail->next = new Node{d, nullptr};
    }
};