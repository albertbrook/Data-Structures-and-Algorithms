#include <iostream>

// 不带头结点
class LineQueue {
private:
    struct Node {
        int data;
        Node *next;
    } *front, *rear, *p;

public:
    LineQueue() {
        front = rear = nullptr;
    }

    void print() {
        p = front;
        while (p != nullptr) {
            printf("%d\n", p->data);
            p = p->next;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void push(int data) {
        p = new Node{data, nullptr};
        if (front == nullptr)
            front = rear = p;
        else
            rear = rear->next = p;
    }

    int pop() {
        if (isEmpty())
            return -1;
        p = front;
        front = p->next;
        if (rear == p)
            rear = front;
        int data = p->data;
        delete p;
        return data;
    }
};