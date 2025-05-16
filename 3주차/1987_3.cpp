#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, ret;
string s;
char a[24][24];
bool visited[26];

void go(int y, int x, int count) {
    ret = max(ret, count);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        int next = a[ny][nx] - 'A';
        if (visited[next]) continue;

        visited[next] = true;
        go(ny, nx, count + 1);
        visited[next] = false;
    }
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

    visited[a[0][0] - 'A'] = 1;
    go(0, 0, 1);
    cout << ret << '\n';

    return 0;
}