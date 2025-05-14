#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
string s;
int n, m, a[54][54], ret, visited[54][54];

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
    
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (a[ny][nx] == 1 || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return visited[y][x];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0 ; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'W') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                memset(visited, 0, sizeof(visited));
                ret = max(ret, bfs(i, j));
            }
        }
    }

    cout << ret - 1 << '\n';

    return 0;
}