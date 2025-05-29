#include <bits/stdc++.h>
using namespace std;

const int dy1[] = {0, -1, 0, 1};
const int dx1[] = {1, 0, -1, 0};
const int dy2[] = {0, 1, 0, -1};
const int dx2[] = {1, 0, -1, 0};
int n, m, t, ret, a[54][54], b[54][54];
vector<pair<int, int>> v1, v2;

void mise(const int dy[], const int dx[]) {
    fill(&b[0][0], &b[0][0] + 54 * 54, 0);
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != -1 && a[i][j] != 0) {
                q.push({i, j});
            }
        }
    }

    while (q.size()) {
        int y, x; tie(y, x) = q.front(); q.pop();

        int spread = a[y][x] / 5;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (a[ny][nx] == -1) continue;
            b[ny][nx] += spread;
            a[y][x] -= spread;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == -1) continue;
            a[i][j] += b[i][j];
        }
    }
}

vector<pair<int, int>> chung(int sy, int sx, const int dy[], const int dx[]) {
    vector<pair<int, int>> v;
    int y = sy, x = sx;
    int cnt = 0;

    while (true) {
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];

        if (ny == sy && nx == sx) break;
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
            cnt++;
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        }
        y = ny, x = nx;
        v.push_back({ny, nx});
    }
    return v;
}

void go(vector<pair<int, int>>& v) {
    for (int i = v.size() - 1; i > 0; i--) {
        a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
    }
    a[v[0].first][v[0].second] = 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> t;
    bool flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) {
                if (flag) {
                    v1 = chung(i, j, dy1, dx1);
                    flag = 0;
                } else {
                    v2 = chung(i, j, dy2, dx2);
                }
            }
        }
    }
    
    while (t--) {
        mise(dy1, dx1);
        go(v1);
        go(v2);
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