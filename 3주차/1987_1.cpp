#include <bits/stdc++.h>
using namespace std;
#define prev aaa

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, ret, visited[26];
char a[24][24];

void go(int y, int x, int cnt) {
    ret = max(ret, cnt);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (visited[a[ny][nx] - 'A'] == 0) {
            visited[a[ny][nx] - 'A'] = 1;
            go(ny, nx, cnt + 1);
            visited[a[ny][nx] - 'A'] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin>> a[i][j];
        }
    }

    visited[a[0][0] - 'A'] = 1;
    go(0, 0, 1);
    cout << ret;
    return 0;
}