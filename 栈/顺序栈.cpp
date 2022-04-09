#include <iostream>

#define MaxSize 50

class SequenceStack {
private:
    struct SqStack {
        int data[MaxSize];
        int top;
    } SqStack;

public:
    SequenceStack() {
        SqStack.top = -1;
    }

    void push(int data) {
        if (SqStack.top == MaxSize - 1)
            return;
        SqStack.data[++SqStack.top] = data;
    }

    int pop() {
        if (SqStack.top == -1)
            return -1;
        return SqStack.data[SqStack.top--];
    }

    int getTop() {
        if (SqStack.top == -1)
            return -1;
        return SqStack.data[SqStack.top];
    }

    bool isEmpty() {
        return SqStack.top == -1;
    }

    void print() {
        for (int i = SqStack.top; i >= 0; --i)
            printf("%d\n", SqStack.data[i]);
    }
};