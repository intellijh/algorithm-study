#include <bits/stdc++.h>
using namespace std;
#define prev ppp

const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
int n, y, x, dir, g, a[104][104], ret;
pair<int, int> p;
vector<int> v[4][11];

void dragon() {
    for (int i = 0; i < 4; i++) {
        v[i][0].push_back(i);
        v[i][1].push_back((i + 1) % 4);

        for (int j = 2; j <= 10; j++) {
            int s = v[i][j - 1].size();
            
            for (int k = s - 1; k >= 0; k--) {
                v[i][j].push_back((v[i][j - 1][k] + 1) % 4);
            }

            for (int k = 0; k < s; k++) {
                v[i][j].push_back(v[i][j - 1][k]);
            }
        }
    }
}

void go(int y, int x, int dir, int g) {
    a[y][x] = 1;
    for (int i = 0; i <= g; i++) {
        for (int j = 0; j < v[dir][i].size(); j++) {
            int d = v[dir][i][j];
            y = y + dy[d];
            x = x + dx[d];
            a[y][x] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    dragon();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> dir >> g;
        go(y, x, dir, g);
    }

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) ret++;
        }
    }

    cout << ret << '\n';
    return 0;
}