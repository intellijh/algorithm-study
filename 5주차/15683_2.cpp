#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int n, m, a[10][10], ret = 1004, y, x;
bool visited[10][10];
vector<pair<int, int>> v;

void check() {
    int temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) temp++;
        }
    }
    ret = min(temp, ret);
}

void go(int idx) {
    if (idx == v.size()) {
        check();
        return;
    }
    
    tie(y, x) = v[idx];
    visited[y][x] = 1;
    int t = a[y][x];

    bool temp[10][10];
    memcpy(temp, visited, sizeof(visited));
    int sy = y, sx = x;
    if (t == 1) {
        for (int i = 0; i < 4; i++) {
            y = sy, x = sx;
            while (true) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
                visited[ny][nx] = 1;
                y = ny, x = nx;
            }
            
            go(idx + 1);
            memcpy(visited, temp, sizeof(temp));
        }
    } else if (t == 2) {
        for (int i = 0; i < 4; i++) {
            y = sy, x = sx;
            while (true) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
                visited[ny][nx] = 1;
                y = ny, x = nx;
            }

            y = sy, x = sx;
            while (true) {
                int ny = y + dy[(i + 2) % 4];
                int nx = x + dx[(i + 2) % 4];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
                visited[ny][nx] = 1;
                y = ny, x = nx;
            }

            go(idx + 1);
            memcpy(visited, temp, sizeof(temp));
        }
    } else if (t == 3) {
        for (int i = 0; i < 4; i++) {
            y = sy, x = sx;
            while (true) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
                visited[ny][nx] = 1;
                y = ny, x = nx;
            }

            y = sy, x = sx;
            while (true) {
                int ny = y + dy[(i + 1) % 4];
                int nx = x + dx[(i + 1) % 4];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
                visited[ny][nx] = 1;
                y = ny, x = nx;
            }

            go(idx + 1);
            memcpy(visited, temp, sizeof(temp));
        }
    } else if (t == 4) {
        for (int i = 0; i < 4; i++) {
            y = sy, x = sx;
            while (true) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
                visited[ny][nx] = 1;
                y = ny, x = nx;
            }

            y = sy, x = sx;
            while (true) {
                int ny = y + dy[(i + 1) % 4];
                int nx = x + dx[(i + 1) % 4];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
                visited[ny][nx] = 1;
                y = ny, x = nx;
            }

            y = sy, x = sx;
            while (true) {
                int ny = y + dy[(i + 2) % 4];
                int nx = x + dx[(i + 2) % 4];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
                visited[ny][nx] = 1;
                y = ny, x = nx;
            }

            go(idx + 1);
            memcpy(visited, temp, sizeof(temp));
        }
    } else {
        for (int i = 0; i < 4; i++) {
            y = sy, x = sx;
            while (true) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 6) break;
                visited[ny][nx] = 1;
                y = ny, x = nx;
            }
        }
        go(idx + 1);
        memcpy(visited, temp, sizeof(temp));
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0 && a[i][j] != 6) v.push_back({i, j});
        }
    }
    
    go(0);
    cout << ret << '\n';

    return 0;
}