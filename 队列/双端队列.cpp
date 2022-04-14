#include <iostream>

class LineQueue {
private:
    struct Node {
        int data;
        Node *prior;
        Node *next;
    } *front, *rear, *p;

public:
    LineQueue() {
        front = rear = nullptr;
    }

    void print(bool next = true) {
        p = next ? front : rear;
        while (p != nullptr) {
            printf("%d\n", p->data);
            p = next ? p->next : p->prior;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void push(int data, bool first = false) {
        if (front == nullptr)
            front = rear = new Node{data, nullptr, nullptr};
        else if (!first)
            rear = rear->next = new Node{data, rear, nullptr};
        else
            front = front->prior = new Node{data, nullptr, front};
    }

    int pop(bool first = true) {
        if (isEmpty())
            return -1;
        if (first) {
            p = front;
            front = p->next;
            if (front == nullptr)
                rear = nullptr;
        } else {
            p = rear;
            rear = p->prior;
            if (rear == nullptr)
                front = nullptr;
        }
        int data = p->data;
        delete p;
        return data;
    }
};