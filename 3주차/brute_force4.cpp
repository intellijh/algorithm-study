#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int a[3][3], visited[3][3];
vector<int> ret;

void print() {
    for (int i : ret) cout << i << " ";
    cout << '\n';
}

void go(int y, int x) {
    if (y == 2 && x == 2) {
        print();
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= 3 || nx >= 3) continue;
        if (visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        ret.push_back(a[ny][nx]);

        go(ny, nx);

        visited[ny][nx] = 0;
        ret.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    visited[0][0] = 1;
    ret.push_back(a[0][0]);
    go(0, 0);
    return 0;
}