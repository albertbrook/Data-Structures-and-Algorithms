#include <iostream>

#define MaxSize 50

// 牺牲一个空间区分队空和队满
class CircularQueue {
private:
    struct SqQueue {
        int data[MaxSize];
        int front, rear;
    } SqQueue;

public:
    CircularQueue() {
        clear();
    }

    void clear() {
        SqQueue.front = SqQueue.rear = 0;
    }

    int size() {
        return (SqQueue.rear + MaxSize - SqQueue.front) % MaxSize;
    }

    void print() {
        for (int i = 0; i < size(); ++i)
            printf("%d\n", SqQueue.data[(SqQueue.front + i) % MaxSize]);
    }

    bool isEmpty() {
        return SqQueue.front == SqQueue.rear;
    }

    bool isFull() {
        return (SqQueue.rear + 1) % MaxSize == SqQueue.front;
    }

    void push(int data) {
        if (isFull())
            return;
        SqQueue.data[SqQueue.rear] = data;
        SqQueue.rear = (SqQueue.rear + 1) % MaxSize;
    }

    int pop() {
        if (isEmpty())
            return -1;
        int data = SqQueue.data[SqQueue.front];
        SqQueue.front = (SqQueue.front + 1) % MaxSize;
        return data;
    }
};