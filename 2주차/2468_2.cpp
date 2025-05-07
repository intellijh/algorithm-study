#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, ret = 1, cnt, mx;
int a[104][104];
bool visited[104][104];

void dfs(int y, int x, int k) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx] || a[ny][nx] <= k) continue;

        dfs(ny, nx, k);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }

    for (int k = 1; k <= mx; k++) {
        cnt = 0;
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && a[i][j] > k) {
                    dfs(i, j, k);
                    cnt++;
                }
            }
        }
        ret = max(ret, cnt);
    }

    cout << ret << '\n';

    return 0;
}