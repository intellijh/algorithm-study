#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, t, ret, a[54][54], b[54][54];
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) v.push_back({i, j});
        }
    }
    copy(&a[0][0], &a[0][0] + 54 * 54, &b[0][0]);
    
    while (t--) {
        fill(&b[0][0], &b[0][0] + 54 * 54, 0);
        b[v[0].first][v[0].second] = -1;
        b[v[1].first][v[1].second] = -1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == -1 || a[i][j] == 0) continue;

                int spread = a[i][j] / 5;
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    
                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                    if (a[ny][nx] == -1) continue;
                    b[ny][nx] += spread;
                    cnt++;
                }
                b[i][j] += (a[i][j] - spread * cnt);
            }
        }
        
        //공청기 위
        int y, x; tie(y, x) = {v[0].first, v[0].second};
        
        //무한루프 해제
        while (true) {
            if (x == 0 && y > 0) {
                if (y == v[0].first && x == v[0].second) b[y - 1][x] = 0;
                else b[y][x] = b[y - 1][x];
                y--;
            }
            else if (y == 0 && x < m - 1) b[y][x] = b[y][x + 1], x++;
            else if (x == m - 1 && y < v[0].first) b[y][x] = b[y + 1][x], y++;
            else if (y == v[0].first && x > 0) {
                if (b[y][x - 1] != -1) {
                    b[y][x] = b[y][x - 1];
                } else if (x == 1) {
                    b[y][x] = 0;
                    break;
                }
                x--;
            }
        }
        
        //공청기 아래
        tie(y, x) = {v[1].first, v[1].second};
        
        //무한루프 해제
        while (true) {
            if (x == 0 && y < n - 1) {
                if (y == v[1].first && x == v[1].second) b[y + 1][x] = 0;
                else b[y][x] = b[y + 1][x];
                y++;
            }
            else if (y == n - 1 && x < m - 1) b[y][x] = b[y][x + 1], x++;
            else if (x == m - 1 && y > v[1].first) b[y][x] = b[y - 1][x], y--;
            else if (y == v[1].first && x > 0) {
                if (b[y][x - 1] != -1) {
                    b[y][x] = b[y][x - 1];
                } else if (x == 1) {
                    b[y][x] = 0;
                    break;
                }
                x--;
            }
        }
        copy(&b[0][0], &b[0][0] + 54 * 54, &a[0][0]);
    }
    
    //미세먼지 총합
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == -1) continue;
            ret += a[i][j];
        }
    }

    cout << ret << '\n';
    return 0;
}