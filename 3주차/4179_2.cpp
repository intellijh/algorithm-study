#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

const int INF = 987654321;
int n, m, ret = INF, y, x;
char a[1004][1004];
queue<pair<int, int>> q;
pair<int, int> jh;
int person[1004][1004], fire[1004][1004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INF);
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'J') jh = {i, j};
            else if (a[i][j] == 'F') {
                q.push({i, j});
                fire[i][j] = 1;
            }
        }
    }
    
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx <0 || ny >= n || nx >= m) continue;
            if (fire[ny][nx] != INF || a[ny][nx] == '#') continue;
            fire[ny][nx] = fire[y][x] + 1;
            q.push({ny, nx});
        }
    }
    
    q.push({jh.first, jh.second});
    person[jh.first][jh.second] = 1;
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        
        if (y == 0 || x == 0 || y == n - 1 || x == m - 1) {
            ret = person[y][x];
            break;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (person[ny][nx] != 0 || a[ny][nx] == '#') continue;
            if (fire[ny][nx] <= person[y][x] + 1) continue;
            person[ny][nx] = person[y][x] + 1;
            q.push({ny, nx});
        }
    }


    if (ret == INF) cout << "IMPOSSIBLE" << '\n';
    else cout << ret << '\n';
    return 0;
}