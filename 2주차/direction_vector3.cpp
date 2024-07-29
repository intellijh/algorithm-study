#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int a[3][3];
bool visited[3][3];

void go(int y, int x) {
    visited[y][x] = 1;
    cout << y << " : " << x << '\n';
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny > 2 || nx > 2) continue;
        if (visited[ny][nx] || a[ny][nx] == 0) continue;
        go(ny, nx);
    }
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    go(0, 0);
    return 0;
}