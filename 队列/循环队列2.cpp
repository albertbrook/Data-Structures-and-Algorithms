#include <iostream>

#define MaxSize 50

// 根据元素个数区分队空和队满
class CircularQueue {
private:
    struct SqQueue {
        int data[MaxSize];
        int front, rear;
        int size;
    } SqQueue;

public:
    CircularQueue() {
        clear();
    }

    void clear() {
        SqQueue.front = SqQueue.rear = SqQueue.size = 0;
    }

    int size() {
        return SqQueue.size;
    }

    void print() {
        for (int i = 0; i < size(); ++i)
            printf("%d\n", SqQueue.data[(SqQueue.front + i) % MaxSize]);
    }

    bool isEmpty() {
        return !SqQueue.size;
    }

    bool isFull() {
        return SqQueue.size == MaxSize;
    }

    void push(int data) {
        if (isFull())
            return;
        SqQueue.data[SqQueue.rear] = data;
        SqQueue.rear = (SqQueue.rear + 1) % MaxSize;
        ++SqQueue.size;
    }

    int pop() {
        if (isEmpty())
            return -1;
        int data = SqQueue.data[SqQueue.front];
        SqQueue.front = (SqQueue.front + 1) % MaxSize;
        --SqQueue.size;
        return data;
    }
};