#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, a[10][10], b[10][10], visited[10][10], ret, temp;
vector<pair<int, int>> v;

void count() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (b[i][j] == 0) cnt++;
        }
    }
    ret = max(ret, cnt);
}

void dfsVirus(int y, int x) {
    visited[y][x] = 1;
    if (b[y][x] == 0) b[y][x] = 2;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (visited[ny][nx] || b[ny][nx] == 1 || b[ny][nx] == 2) continue;
        dfsVirus(ny, nx);
    }
}

void combi(int start, vector<pair<int, int>> v) {
    if (v.size() == 3) {
        memcpy(b, a, sizeof(a));
        fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
        temp = 0;

        int y, x;
        for (int i = 0; i < 3; i++) {
            tie(y, x) = v[i];
            b[y][x] = 1;
        }

        //바이러스 이동
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && b[i][j] == 2) dfsVirus(i, j);
            }
        }
        count();
        return;
    }

    for (int i = start + 1; i < N * M; i++) {
        int y = i / M, x = i % M;
        if (a[y][x] == 2 || a[y][x] == 1) continue;
        v.push_back({y, x});
        combi(i, v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    memcpy(b, a, sizeof(a));
    combi(-1, v);
    cout << ret;

    return 0;
}