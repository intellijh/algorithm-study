#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, 1, 1};
const int dx[] = {1, 1, 0};
int n, a[18][18], dp[3][18][18];

int go(int d, int y, int x) {
    if (a[y][x] == 1) return 0;
    if (d == 1 && (a[y - 1][x] == 1 || a[y][x - 1] == 1)) return 0;
    if (y == n - 1 && x == n - 1) return 1;

    int& ret = dp[d][y][x];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < 3; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (d == 0 && i == 2) continue;
        if (d == 2 && i == 0) continue;
        ret += go(i, ny, nx);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << go(0, 0, 1) << '\n';

    return 0;
}