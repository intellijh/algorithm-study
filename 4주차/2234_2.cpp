#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
int n, m, mx1, mx2, cnt, a[54][54];
int visited[54][54], compSize[2504];

int dfs(int y, int x, int cnt) {
    int count = 1;
    visited[y][x] = cnt;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (visited[ny][nx] || (a[y][x] & (1 << i))) continue;
        count += dfs(ny, nx, cnt);
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                cnt++;
                compSize[cnt] = dfs(i, j, cnt);
                mx1 = max(mx1, compSize[cnt]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n) {
                int a = visited[i][j];
                int b = visited[i + 1][j];
                if (a != b) {
                    mx2 = max(mx2, compSize[a] + compSize[b]);
                }
            }
            if (j + 1 < m) {
                int a = visited[i][j];
                int b = visited[i][j + 1];
                if (a != b) {
                    mx2 = max(mx2, compSize[a] + compSize[b]);
                }
            }
        }
    }

    cout << cnt << '\n';
    cout << mx1 << '\n';
    cout << mx2 << '\n';

    return 0;
}