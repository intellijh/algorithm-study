#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N, M, cnt;
int adj[104][104];
bool visited[104][104];

void dfs(int y, int x) {
    visited[y][x] = 1;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (visited[ny][nx] || adj[ny][nx] == 0) continue;
        dfs(ny, nx);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (adj[i][j] == 1 && !visited[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt;
    return 0;
}