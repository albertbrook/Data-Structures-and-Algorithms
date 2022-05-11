#include <iostream>

#define MaxSize 100

class SequentialString {
private:
    struct SString {
        char ch[MaxSize];
        int length;
    } SString;

public:
    SequentialString() {
        SString.length = 0;
    }

    void print() {
        for (int i = 0; i < SString.length; ++i)
            printf("%c", SString.ch[i]);
        printf("\n");
    }

    void strAssign(int index, char c) {
        SString.ch[index] = c;
        ++SString.length;
    }

    void strInsert(int index, char c) {
        if (SString.length == MaxSize)
            return;
        for (int i = SString.length - 1; i >= index; --i)
            SString.ch[i + 1] = SString.ch[i];
        SString.ch[index] = c;
        ++SString.length;
    }

    void strDelete(int index) {
        if (SString.length == 0)
            return;
        for (int i = index; i < SString.length - 1; ++i)
            SString.ch[i] = SString.ch[i + 1];
        --SString.length;
    }

    void strCopy(SequentialString &s) {
        s.SString.length = SString.length;
        for (int i = 0; i < SString.length; ++i)
            s.SString.ch[i] = SString.ch[i];
    }

    int strCompare(SequentialString &s) {
        for (int i = 0; i < SString.length; ++i)
            if (SString.ch[i] > s.SString.ch[i])
                return 1;
            else if (SString.ch[i] < s.SString.ch[i])
                return -1;
        return 0;
    }

    int strLength() {
        return SString.length;
    }

    void subString(SequentialString &s, int start, int end) {
        s.SString.length = end - start;
        for (int i = start; i < end; ++i)
            s.SString.ch[i - start] = SString.ch[i];
    }
};