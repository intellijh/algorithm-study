#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m, a[104][104], visited[104][104];
string s;

void bfs(int y, int x) {
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx] || a[ny][nx] == 0) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    bfs(0, 0);
    cout << visited[n - 1][m - 1] << '\n';
    return 0;
}