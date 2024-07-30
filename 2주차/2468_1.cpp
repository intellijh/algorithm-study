#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, adj[104][104], visited[104][104], ret = 1, cnt, mx;

void dfs(int y, int x, int t) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (visited[ny][nx] || adj[ny][nx] <= t) continue;
        dfs(ny, nx, t);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
            mx = max(mx, adj[i][j]);
        }
    }


    for (int t = 1; t < mx; t++) {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] || adj[i][j] <= t) continue;
                dfs(i, j, t);
                cnt++;
            }
        }
        ret = max(ret, cnt);
    }

    cout << ret;
    return 0;
}