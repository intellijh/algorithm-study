#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
int n, m, mx1, mx2, cnt, a[54][54];
bool visited[54][54];

int dfs(int y, int x) {
    int count = 1;
    visited[y][x] = 1;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx] || (a[y][x] & (1 << i))) continue;
        count += dfs(ny, nx);
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
                mx1 = max(mx1, dfs(i, j));
                cnt++;
            }
        }
    }

    mx2 = mx1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                if (a[i][j] & (1 << k)) {
                    a[i][j] &= ~(1 << k);
                    fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
                    mx2 = max(mx2, dfs(i, j));
                    a[i][j] |= (1 << k);
                }
            }
        }
    }

    cout << cnt << '\n';
    cout << mx1 << '\n';
    cout << mx2 << '\n';

    return 0;
}