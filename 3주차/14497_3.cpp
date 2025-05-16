#include <bits/stdc++.h>
using namespace std;

#define y1 yyy

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, y1, y2, x1, x2, ret;
char a[304][304];
string s;
bool visited[304][304];

void dfs(int y, int x) {
    visited[y][x] = 1;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (visited[ny][nx]) continue;
        if (a[ny][nx] == '1') {
            a[ny][nx] = '0';
            visited[ny][nx] = 1;
            continue;
        }
        if (a[ny][nx] == '#') {
            cout << ret << '\n';
            exit(0);
        }
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    for (int i = 0; i < 304; i++) {
        memset(visited, 0, sizeof(visited));
        ret = i + 1;
        dfs(y1 - 1, x1 - 1);
    }

    return 0;
}