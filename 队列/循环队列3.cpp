#include <iostream>

#define MaxSize 50

// 根据最后的操作区分队空和队满
class CircularQueue {
private:
    struct SqQueue {
        int data[MaxSize];
        int front, rear;
        bool tag;
    } SqQueue;

public:
    CircularQueue() {
        clear();
    }

    void clear() {
        SqQueue.front = SqQueue.rear = 0;
        SqQueue.tag = false;
    }

    int size() {
        int size = (SqQueue.rear + MaxSize - SqQueue.front) % MaxSize;
        return size ? size : (SqQueue.tag ? MaxSize : 0);
    }

    void print() {
        for (int i = 0; i < size(); ++i)
            printf("%d\n", SqQueue.data[(SqQueue.front + i) % MaxSize]);
    }

    bool isEmpty() {
        return SqQueue.front == SqQueue.rear && !SqQueue.tag;
    }

    bool isFull() {
        return SqQueue.front == SqQueue.rear && SqQueue.tag;
    }

    void push(int data) {
        if (isFull())
            return;
        SqQueue.data[SqQueue.rear] = data;
        SqQueue.rear = (SqQueue.rear + 1) % MaxSize;
        SqQueue.tag = true;
    }

    int pop() {
        if (isEmpty())
            return -1;
        int data = SqQueue.data[SqQueue.front];
        SqQueue.front = (SqQueue.front + 1) % MaxSize;
        SqQueue.tag = false;
        return data;
    }
};