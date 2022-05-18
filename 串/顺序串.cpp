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
        initArray();
    }

    void print() {
        for (int i = 0; i < SString.length; ++i)
            printf("%c", SString.ch[i]);
        printf("\n");
    }

    void strAssign(int index, char c) {
        if (index < 0 || index > SString.length)
            return;
        SString.ch[index] = c;
        ++SString.length;
    }

    void strInsert(int index, char c) {
        if (SString.length == MaxSize || index < 0 || index > SString.length)
            return;
        for (int i = SString.length - 1; i >= index; --i)
            SString.ch[i + 1] = SString.ch[i];
        SString.ch[index] = c;
        ++SString.length;
    }

    void strDelete(int index) {
        if (SString.length == 0 || index < 0 || index >= SString.length)
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
        int minLength = s.SString.length < SString.length ? s.SString.length : SString.length;
        for (int i = 0; i < minLength; ++i)
            if (SString.ch[i] > s.SString.ch[i])
                return 1;
            else if (SString.ch[i] < s.SString.ch[i])
                return -1;
        return s.SString.length == SString.length ? 0 : (SString.length > s.SString.length ? 1 : -1);
    }

    int strLength() {
        return SString.length;
    }

    void subString(SequentialString &s, int start, int end) {
        s.SString.length = end - start;
        for (int i = start; i < end; ++i)
            s.SString.ch[i - start] = SString.ch[i];
    }
    
    void initArray() {
        SString.length = 0;
    }
    
    char getValue(int index) {
        return SString.ch[index];
    }
};