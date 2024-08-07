#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, ret, visited[1004][1004], visitedFire[1004][1004];
char a[1004][1004];
pair<int, int> jihun;
queue<pair<int, int>> fire;

void bfs() {
    int y, x;

    while (fire.size()) {
        tie(y, x) = fire.front(); fire.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];   
            int nx = x + dx[i];   
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (visitedFire[ny][nx] != INF || a[ny][nx] == '#') continue;
            visitedFire[ny][nx] = visitedFire[y][x] + 1;
            fire.push({ny, nx});
        }
    }
}

void bfsJihun(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;

    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        if (y == 0 || x == 0 || y == N - 1 || x == M - 1) {
            ret = visited[y][x];
            return;
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];   
            int nx = x + dx[i];   
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (visited[ny][nx] || a[ny][nx] == '#') continue;
            if (visitedFire[ny][nx] <= visited[y][x] + 1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    fill(&visitedFire[0][0], &visitedFire[0][0] + 1004 * 1004, INF);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'J') jihun = {i, j};
            if (a[i][j] == 'F') {
                fire.push({i, j});
                visitedFire[i][j] = 1;
            }
        }
    }

    bfs();
    bfsJihun(jihun.first, jihun.second);

    if (ret == 0) cout << "IMPOSSIBLE";
    else cout << ret;
    return 0;
}