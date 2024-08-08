#include <bits/stdc++.h>
using namespace std;
#define y1 aaa

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, ret, x1, y1, x2, y2;
char a[304][304], visited[304][304];

void bfs(int y, int x) {
    queue<pair<int, int>> q, one;
    q.push({y, x});
    visited[y][x] = 1;
    
    while (true) {
        ret++;
        while (!q.empty()) {
            tie(y, x) = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
                visited[ny][nx] = 1;
                if (a[ny][nx] == '1') {
                    a[ny][nx] = '0';
                    one.push({ny, nx});
                } else {
                    q.push({ny, nx});
                }
                if (a[ny][nx] == '#') return;
            }
        }

        q = one;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    bfs(x1 - 1, y1 - 1);
    cout << ret;
    return 0;
}