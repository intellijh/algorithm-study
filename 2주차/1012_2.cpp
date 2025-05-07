#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int t, n, m, k, yy, xx, ret;
int a[54][54];
bool visited[54][54];

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (a[ny][nx] == 0 || visited[ny][nx]) continue;

        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--) {
        cin >> m >> n >> k;

        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));
        ret = 0;

        for (int i = 0; i < k; i++) {
            cin >> xx >> yy;
            a[yy][xx] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && a[i][j] > 0) {
                    dfs(i, j);
                    ret++;
                }
            }
        }

        cout << ret << '\n';
    }
    
    return 0;
}