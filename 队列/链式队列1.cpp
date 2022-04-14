#include <iostream>

// 带头结点
class LineQueue {
private:
    struct Node {
        int data;
        Node *next;
    } *front, *rear, *p;

public:
    LineQueue() {
        front = rear = new Node{0, nullptr};
    }

    void print() {
        p = front->next;
        while (p != nullptr) {
            printf("%d\n", p->data);
            p = p->next;
        }
    }

    bool isEmpty() {
        return front == rear;
    }

    void push(int data) {
        rear = rear->next = new Node{data, nullptr};
        ++front->data;
    }

    int pop() {
        if (isEmpty())
            return -1;
        p = front->next;
        front->next = p->next;
        if (rear == p)
            rear = front;
        int data = p->data;
        delete p;
        --front->data;
        return data;
    }
};