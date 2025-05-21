#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, ret;
char a[24][24];

void go(int y, int x, int num, int cnt) {
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (num & (1 << (a[ny][nx] - 'A'))) continue;
        go(ny, nx, num | (1 << (a[ny][nx] - 'A')), cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    go(0, 0, (1 << (a[0][0] - 'A')), 1);

    cout << ret << '\n';

    return 0;
}