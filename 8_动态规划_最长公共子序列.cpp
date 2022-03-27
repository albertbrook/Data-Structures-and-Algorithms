#include <iostream>

using namespace std;

int main() {
    string a = "visit", b = "first", cs;
    int dp[a.length() + 1][b.length() + 1], i, j, lcs = 0;

    for (i = 0; i <= a.length(); ++i) {
        for (j = 0; j <= b.length(); ++j) {
            if (!i || !j) {
                dp[i][j] = 0;
                printf("%-3c%c", j ? b[j - 1] : a[i - 1], j != b.length() ? ' ' : '\n');
                continue;
            }
            dp[i][j] = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
            if (dp[i][j] > lcs) {
                lcs = dp[i][j];
                cs += a[i - 1];
            }
            printf("%-3d%c", dp[i][j], j != b.length() ? ' ' : '\n');
        }
    }
    cout << '\n' << cs << endl;
    return 0;
}