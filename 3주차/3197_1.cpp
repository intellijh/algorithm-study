#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, ret, visited[1504][1504], swanVisited[1504][1504];
char a[1504][1504];
queue<pair<int, int>> swanQ, waterQ;
pair<int, int> l;

void qClear(queue<pair<int, int>> &q) {
    queue<pair<int, int>> empty;
    swap(q, empty);
}

void water() {
    queue<pair<int, int>> q;
    q = waterQ;
    qClear(waterQ);
    int y, x;
    while (!q.empty()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] ) continue;


            visited[ny][nx] = 1;
            if (a[ny][nx] == 'X') {
                a[ny][nx] = '.';
                waterQ.push({ny, nx});
                continue;
            }
            q.push({ny, nx});
        }
    }
}

void swan() {
    while (true) {
        queue<pair<int, int>> q;
        q = swanQ;
        qClear(swanQ);
        int y, x;
        while (!q.empty()) {
            tie(y, x) = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M || swanVisited[ny][nx] ) continue;

                swanVisited[ny][nx] = 1;
                if (a[ny][nx] == 'X') {
                    swanQ.push({ny, nx});
                    continue;
                }
                if (a[ny][nx] == 'L') {
                    return;
                }
                q.push({ny, nx});
            }
        }

        water();
        ret++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'L') l = {i, j};
            if (a[i][j] == '.' || a[i][j] == 'L') {
                visited[i][j] = 1;
                waterQ.push({i, j});
            }
        }
    }

    swanQ.push({l.first, l.second});
    swanVisited[l.first][l.second] = 1;
    swan();
        
    cout << ret;
    return 0;
}