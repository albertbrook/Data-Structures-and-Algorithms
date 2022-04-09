#include <iostream>

class LineStack {
private:
    struct Node {
        int data;
        Node *next;
    } *head, *p;

public:
    LineStack() {
        head = new Node{0, nullptr};
    }

    void print() {
        p = head;
        while (p != nullptr) {
            printf("%d\n", p->data);
            p = p->next;
        }
    }

    void push(int data) {
        head->next = new Node{data, head->next};
        ++head->data;
    }

    int pop() {
        if (!head->data)
            return -1;
        p = head->next;
        head->next = p->next;
        int data = p->data;
        delete p;
        --head->data;
        return data;
    }

    int getTop() {
        if (!head->data)
            return -1;
        return head->next->data;
    }
};