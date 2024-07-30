#include <bits/stdc++.h>
using namespace std;
#define y1 aaaa

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int M, N, K, x1, x2, y1, y2, adj[104][104], visited[104][104];
int ny, nx;
vector<int> ret;

int dfs(int y, int x) {
    visited[y][x] = 1;
    int ret = 1;

    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
        if (visited[ny][nx] || adj[ny][nx] == 1) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                adj[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] || adj[i][j] == 1) continue;
            ret.push_back(dfs(i, j));
        }
    }
    
    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for (int i : ret) {
        cout << i << " ";
    }

    return 0;
}