#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int INF = 1e9;
int n, m, t, d, a[26][26], b[3000][3000], ret;
char temp;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> t >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            if (temp >= 'a') a[i][j] = temp - 'a' + 26;
            else a[i][j] = temp - 'A';
        }
    }

    ret = a[0][0];
    fill(&b[0][0], &b[0][0] + 3000 * 3000, INF);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                
                int diff = abs(a[y][x] - a[ny][nx]);
                if (diff <= t) {
                    if (a[y][x] >= a[ny][nx]) {
                        b[y * 100 + x][ny * 100 + nx] = 1;
                    } else {
                        b[y * 100 + x][ny * 100 + nx] = diff * diff;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v.push_back({i * 100 + j});
        }
    } 

    for (int k : v) {
        for (int i : v) {
            for (int j : v) {
                b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
            }
        }
    }

    for (int i : v) {
        if (b[0][i] + b[i][0] <= d) {
            ret = max(ret, a[i / 100][i % 100]);
        }
    }

    cout << ret << '\n';
    return 0;
}