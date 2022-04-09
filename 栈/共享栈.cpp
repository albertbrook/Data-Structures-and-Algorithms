#include <iostream>

#define MaxSize 10

class Stack {
private:
    struct SharedStack {
        int data[MaxSize];
        int top1;
        int top2;
    } ShStack;

public:
    Stack() {
        ShStack.top1 = -1;
        ShStack.top2 = MaxSize;
    }

    void push(int data, bool second = false) {
        if (ShStack.top1 == ShStack.top2 - 1)
            return;
        if (second)
            ShStack.data[--ShStack.top2] = data;
        else
            ShStack.data[++ShStack.top1] = data;
    }

    int pop(bool second = false) {
        if ((!second && ShStack.top1 == -1) || (second && ShStack.top2 == MaxSize))
            return -1;
        return ShStack.data[second ? ShStack.top2++ : ShStack.top1--];
    }

    int getTop(bool second = false) {
        if ((!second && ShStack.top1 == -1) || (second && ShStack.top2 == MaxSize))
            return -1;
        return ShStack.data[second ? ShStack.top2 : ShStack.top1];
    }

    bool isEmpty(bool second = false) {
        return second ? ShStack.top2 == MaxSize : ShStack.top1 == -1;
    }

    void print(bool second = false) {
        if (second)
            for (int i = ShStack.top2; i < MaxSize; ++i)
                printf("%d\n", ShStack.data[i]);
        else
            for (int i = ShStack.top1; i >= 0; --i)
                printf("%d\n", ShStack.data[i]);
    }
};