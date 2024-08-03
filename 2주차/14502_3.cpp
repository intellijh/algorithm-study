#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M, a[10][10], visited[10][10], ret;
vector<pair<int, int>> virusList, wallList;

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (visited[ny][nx] || a[ny][nx] == 1) continue;
        dfs(ny, nx);
    }
}

void solve() {
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    for (auto it : virusList) {
        dfs(it.first, it.second);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }
    ret = max(ret, cnt);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) virusList.push_back({i, j});
            if (a[i][j] == 0) wallList.push_back({i, j});
        }
    }

    int size = wallList.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;
                solve();
                a[wallList[i].first][wallList[i].second] = 0;
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }

    cout << ret;
    return 0;
}