#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[104][104], ret1, ret2, cnt2;
bool visited[104][104];

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx]) continue;
        if (a[ny][nx] == 1) {
            cnt2++;
            visited[ny][nx] = 1;
            a[ny][nx] = 0;
            continue;
        }
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {
        memset(visited, 0, sizeof(visited));
        cnt2 = 0;
        dfs(0, 0);
        
        if (cnt2 == 0) break;
        ret2 = cnt2;
        ret1++;
    }

    cout << ret1 << '\n';
    cout << ret2 << '\n';

    return 0;
}