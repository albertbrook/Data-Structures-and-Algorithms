#include <iostream>

using namespace std;

int main() {
    string names[] = {"sound", "laptop", "guitar", "phone"};
    int values[] = {3000, 2000, 1500, 2000};
    int weights[] = {4, 3, 1, 1};
    const int size = sizeof(names) / sizeof(names[0]), n = 4;
    int dp[size + 1][n + 1] = {}, i, j;

    for (i = 0; i <= size; ++i) {
        for (j = 0; j <= n; ++j) {
            if (!i || !j) {
                if (!j)
                    printf("%-7s ", !i ? "" : names[i - 1].c_str());
                else
                    printf("%-5d%c", j, j != n ? ' ' : '\n');
                continue;
            }
            if (weights[i - 1] <= j)
                dp[i][j] = values[i - 1] + dp[i - 1][j - weights[i - 1]];
            if (weights[i - 1] > j || dp[i][j] < dp[i - 1][j])
                dp[i][j] = dp[i - 1][j];
            printf("%-5d%c", dp[i][j], j != n ? ' ' : '\n');
        }
    }

    j = n;
    for (i = size; i >= 1; --i)
        if (dp[i][j] != dp[i - 1][j]) {
            cout << (j == n ? "\n" : " ") << names[i - 1];
            j -= weights[i - 1];
        }
    cout << endl;
    return 0;
}