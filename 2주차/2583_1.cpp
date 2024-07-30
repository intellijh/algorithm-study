#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int M, N, K, p[104][4], adj[104][104], visited[104][104], cnt, w;
int ny, nx;
vector<int> ret;

void dfs(int y, int x) {
    visited[y][x] = 1;
    w++;

    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
        if (visited[ny][nx] || adj[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> p[i][j];
        }
    }

    for (int i = 0 ; i < K; i++) {
        for (int j = p[i][1]; j < p[i][3]; j++) {
            for (int k= p[i][0]; k < p[i][2]; k++) {
                adj[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] || adj[i][j] == 1) continue;
            w = 0;
            cnt++;
            dfs(i, j);
            ret.push_back(w);
        }
    }
    
    sort(ret.begin(), ret.end());
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++) {
        cout << ret[i] << " ";
    }

    return 0;
}