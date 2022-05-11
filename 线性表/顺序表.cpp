#include <iostream>

#define MaxSize 50

class SequentialList {
private:
    struct SqList {
        int data[MaxSize];
        int length;
    } SqList;

public:
    SequentialList() {
        SqList.length = 0;
    }

    void print() {
        for (int i = 0; i < SqList.length; ++i)
            printf("%d\n", SqList.data[i]);
    }

    void push(int index, int data) {
        if (index < 0 || index > SqList.length || SqList.length == MaxSize)
            return;
        for (int i = SqList.length - 1; i >= index; --i)
            SqList.data[i + 1] = SqList.data[i];
        SqList.data[index] = data;
        ++SqList.length;
    }

    int pop(int index) {
        if (index < 0 || index > SqList.length - 1)
            return -1;
        int data = SqList.data[index];
        for (int i = index; i < SqList.length - 1; ++i)
            SqList.data[i] = SqList.data[i + 1];
        --SqList.length;
        return data;
    }

    int get(int index) {
        if (index < 0 || index > SqList.length - 1)
            return -1;
        return SqList.data[index];
    }

    int index(int data) {
        for (int i = 0; i < SqList.length; ++i)
            if (data == SqList.data[i])
                return i;
        return -1;
    }
};