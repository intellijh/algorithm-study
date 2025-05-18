#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, k, ret;
char a[10][10];
string s;
bool visited[10][10];

void go(int y, int x, int cnt) {
    if (cnt > k) return;
    if (y == n - 1 && x == m - 1) {
        if (cnt == k) ret++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx] || a[ny][nx] == 'T') continue;
        visited[ny][nx] = 1;
        go(ny, nx, cnt + 1);
        visited[ny][nx] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = n - 1; i >= 0; i--) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    visited[0][0] = 1;
    go(0, 0, 1);

    cout << ret << '\n';

    return 0;
}