#include <bits/stdc++.h>

using namespace std;

int main() {
    string a = "abcabeabcaabd";
    string b = "abcabd";
    int next[b.length()], i, j, start = 0;
    for (i = 0; i < b.length(); ++i) {
        next[0] = 0;
        for (j = 1; j <= i; ++j)
            if (b.substr(0, j) == b.substr(i - j + 1, j))
                next[i] = b.substr(0, j).length();
    }
    for (i = 0; i < b.length(); ++i) {
        if (b[i] != a[start + i]) {
            start += i ? i - next[i - 1] : 1;
            cout << start << endl;
            if (start > a.length() - b.length()) {
                start = -1;
                break;
            }
            i = -1;
        }
    }
    if (start != -1) {
        cout << a.substr(start, b.length()) << endl;
        cout << b << endl;
    }
    cout << start << endl;
    return 0;
}