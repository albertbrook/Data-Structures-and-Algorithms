#include <iostream>

#define MaxSize 50

class StaticList {
private:
    struct Node {
        int data;
        int next;
    };

    Node SList[MaxSize];

public:
    StaticList() {
        clear();
    }

    void clear() {
        SList[0] = {0, -1};
        for (int i = 1; i < MaxSize; ++i)
            SList[i].next = -2;
    }

    void print() {
        for (int i = 0; i != -1; i = SList[i].next)
            printf("%d\n", SList[i].data);
    }

    void push(int index, int data) {
        if (index < 0)
            return;
        int i;
        for (i = 1; SList[i].next != -2 && i < MaxSize; ++i);
        if (i == MaxSize)
            return;
        int j;
        for (j = 0; index-- && j != -1; j = SList[j].next);
        if (j == -1)
            return;
        SList[i].data = data;
        SList[i].next = SList[j].next;
        SList[j].next = i;
        ++SList[0].data;
    }

    int pop(int index) {
        if (index < 0)
            return -1;
        int i;
        for (i = 0; index-- && SList[i].next != -1; i = SList[i].next);
        if (SList[i].next == -1)
            return -1;
        int j = SList[i].next;
        SList[i].next = SList[j].next;
        SList[j].next = -2;
        --SList[0].data;
        return SList[j].data;
    }

    int get(int index) {
        if (index < 0)
            return -1;
        int i;
        for (i = SList[0].next; index-- && i != -1; i = SList[i].next);
        if (i == -1)
            return -1;
        return SList[i].data;
    }

    int index(int data) {
        int index = 0;
        for (int i = SList[0].next; i != -1; i = SList[i].next) {
            if (SList[i].data == data)
                return index;
            ++index;
        }
        return -1;
    }
};