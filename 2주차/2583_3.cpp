#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

vector<int> ret;
int n, m, k, yy, xx, yyy, xxx, cnt;
int a[104][104];
bool visited[104][104];

void dfs(int y, int x) {
    cnt++;
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (a[ny][nx] == 1 || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> xx >> yy >> xxx >> yyy;

        for (int y = yy; y < yyy; y++) {
            for (int x = xx; x < xxx; x++) {
                a[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && a[i][j] == 0) {
                cnt = 0;
                dfs(i, j);
                ret.push_back(cnt);
            }
        }
    }

    cout << ret.size() << '\n';
    sort(ret.begin(), ret.end());
    for (int i : ret) {
        cout << i << " ";
    }

    return 0;
}