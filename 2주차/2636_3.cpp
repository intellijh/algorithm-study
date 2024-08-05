#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, a[104][104], visited[104][104], cnt, ret;
vector<pair<int, int>> v;
bool flag;

void dfs(int y, int x) {
    visited[y][x] = 1;
    if (a[y][x] == 1) {
        v.push_back({y, x});
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        v.clear();
        flag = 0;

        dfs(0, 0);
        cnt = v.size();

        for (pair<int, int> p : v) {
            a[p.first][p.second] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) flag = 1;
            }
        }
        ret++;
        if (!flag) break;
    }
    cout << ret << '\n';
    cout << cnt << '\n';
    return 0;
}