#include <bits/stdc++.h>
using namespace std;

int n, a[18][18], dp[3][18][18];

bool check(int d, int y, int x) {
    if (d == 0 || d == 2) {
        if (a[y][x] == 0) return true;
    } else {
        if (a[y][x] == 0 && a[y][x - 1] == 0 && a[y - 1][x] == 0) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    dp[0][1][2] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (check(0, i, j + 1)) dp[0][i][j + 1] += dp[0][i][j];
            if (check(1, i + 1, j + 1)) dp[1][i + 1][j + 1] += dp[0][i][j];

            if (check(0, i, j + 1)) dp[0][i][j + 1] += dp[1][i][j];
            if (check(1, i + 1, j + 1)) dp[1][i + 1][j + 1] += dp[1][i][j];
            if (check(2, i + 1, j)) dp[2][i + 1][j] += dp[1][i][j];

            if (check(1, i + 1, j + 1)) dp[1][i + 1][j + 1] += dp[2][i][j];
            if (check(2, i + 1, j)) dp[2][i + 1][j] += dp[2][i][j];
        }
    }

    int ret = dp[0][n][n];
    ret += dp[1][n][n]; ret += dp[2][n][n];
    cout << ret << '\n';

    return 0;
}