#include <iostream>

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node *prior;
        Node *next;
    } *head, *tail, *p;

public:
    DoublyLinkedList() {
        head = tail = new Node{0, nullptr, nullptr};
    }

    void print() {
        p = head;
        while (p != nullptr) {
            printf("%d\n", p->data);
            p = p->next;
        }
    }

    void headInsert(int data) {
        head->next = new Node{data, head, head->next};
        if (head->next->next == nullptr)
            tail = head->next;
        else
            head->next->next->prior = head->next;
        ++head->data;
    }

    void tailInsert(int data) {
        tail = tail->next = new Node{data, tail, nullptr};
        ++head->data;
    }

    void push(int i, int data) {
        if (i < 0 || i > head->data)
            return;
        p = head;
        while (i--)
            p = p->next;
        p->next = new Node{data, p, p->next};
        if (p->next->next == nullptr)
            tail = p->next;
        else
            p->next->next->prior = p->next;
        ++head->data;
    }

    void pop(int i) {
        if (i < 0 || i >= head->data)
            return;
        p = head->next;
        while (i--)
            p = p->next;
        p->prior->next = p->next;
        if (p->next == nullptr)
            tail = p->prior;
        else
            p->next->prior = p->prior;
        delete p;
        --head->data;
    }
};