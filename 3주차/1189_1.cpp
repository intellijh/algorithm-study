#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, k, cnt, visited[10][10];
char a[10][10];

void go(int y, int x, int sum) {
    if (sum > k) return;
    if (y == n -1 && x == m - 1) {
        if (sum == k) cnt++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx] || a[ny][nx] == 'T') continue;
        visited[ny][nx] = 1;
        go(ny, nx, sum + 1);
        visited[ny][nx] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = n -1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    visited[0][0] = 1;
    go(0, 0, 1);
    cout << cnt;
    return 0;
}