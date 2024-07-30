#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int T, N, M, K, adj[54][54], visited[54][54], cnt;

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (visited[ny][nx] || adj[ny][nx] == 0) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> M >> N >> K;
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
        cnt = 0;

        for (int i = 0; i < K; i++) {
            int f, s;
            cin >> f >> s;
            adj[s][f] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] || adj[i][j] == 0) continue;
                dfs(i, j);
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}