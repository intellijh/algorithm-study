#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, ret;
string s;
char a[24][24];
bool visited[200];

void go(int y, int x, int count) {
    count++;
    ret = max(ret, count);
    visited[a[y][x]] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[a[ny][nx]]) continue;
        go(ny, nx, count);
    }
    visited[a[y][x]] = false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    go(0, 0, 0);
    cout << ret << '\n';

    return 0;
}