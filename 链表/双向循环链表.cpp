#include <iostream>

class DoubleCircularLinkedList {
private:
    struct Node {
        int data;
        Node *prior;
        Node *next;
    } *head, *p;

public:
    DoubleCircularLinkedList() {
        head = new Node{0};
        head->prior = head->next = head;
    }

    void print() {
        p = head;
        do {
            printf("%d\n", p->data);
            p = p->next;
        } while (p != head);
    }

    void push(int i, int data) {
        if (i < 0 || i > head->data)
            return;
        p = head;
        while (i--)
            p = p->next;
        p->next = p->next->prior = new Node{data, p, p->next};
        ++head->data;
    }

    void pop(int i) {
        if (i < 0 || i >= head->data)
            return;
        p = head->next;
        while (i--)
            p = p->next;
        p->prior->next = p->next;
        p->next->prior = p->prior;
        delete p;
        --head->data;
    }
};