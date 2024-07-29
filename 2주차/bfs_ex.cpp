#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N, M, py, px, desy, desx;
int adj[104][104];
int visited[104][104];

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (visited[ny][nx] || adj[ny][nx] == 0) continue;
            
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    cin >> N >> M;
    cin >> py >> px;
    cin >> desy >> desx;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> adj[i][j];
        }
    }

    bfs(py, px);
    cout << visited[desy][desx] - visited[py][px] + 1;
    return 0;
}