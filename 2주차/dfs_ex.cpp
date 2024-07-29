#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N, M, cnt;
int adj[104][104];
bool visited[104][104];

bool dfs(int y, int x) {
    if (visited[y][x] || adj[y][x] == 0) return 0;
    visited[y][x]++;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        dfs(ny, nx);
    }
    return 1;
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
            if (dfs(i, j) == 1) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}