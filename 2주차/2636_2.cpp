#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[104][104], visited[104][104], cnt, ret;
vector<int> v;

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        if (a[ny][nx] == 1) {
            visited[ny][nx] = 1;
            continue;
        }
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) cnt++;
        }
    }
    v.push_back(cnt);

    while (true) {
        cnt = 0;
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        dfs(0, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) cnt++;
                if (visited[i][j]) {
                    a[i][j] = 0;
                }
            }
        }
        if (cnt == 0) break;
        v.push_back(cnt);
        ret++;
    }
    cout << ret << '\n';
    cout << v[v.size() - 1] << '\n';
    return 0;
}