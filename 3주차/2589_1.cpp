#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0 , -1};
int n, m, a[54][54], visited[54][54], ret;
char temp;

void bfs(int y, int x) {
    fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});

    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx] || a[ny][nx] == 1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            ret = max(ret, visited[ny][nx]);
            q.push({ny, nx});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            if (temp == 'W') a[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) continue;
            bfs(i, j);
        }
    }
    
    cout << ret - 1;
    return 0;
}