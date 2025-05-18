#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, a[14][14], ret = 987654321;
bool visited[14][14];

bool check(int y, int x) {
    if (visited[y][x]) return false;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) return false;
    }
    return true;
}

int setFlower(int y, int x) {
    visited[y][x] = 1;
    int sum = a[y][x];

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        sum += a[ny][nx];
    }
    return sum;
}

void eraseFlower(int y, int x) {
    visited[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}

void flower(int cnt, int sum) {
    if (cnt == 3) {
        ret = min(ret, sum);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j)) {
                flower(cnt + 1, sum + setFlower(i, j));
                eraseFlower(i, j);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    flower(0, 0);
    cout << ret << '\n';

    return 0;
}