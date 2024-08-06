#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, L, R, a[54][54], visited[54][54], sum, ret;
vector<pair<int, int>> v;

int dfs(int y, int x) {
    visited[y][x] = 1;
    v.push_back({y, x});
    int sum = a[y][x];

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        if (visited[ny][nx]) continue;
        int temp = abs(a[ny][nx] - a[y][x]);
        if (temp < L || temp > R) continue;
        sum += dfs(ny, nx);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> L >> R;
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    while (true) {
        bool flag = false;
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) continue;
                sum += dfs(i, j);
                if (sum != a[i][j]) {
                    flag = true;
                    for (pair<int, int> it : v) {
                        a[it.first][it.second] = sum / v.size();
                    }
                }
                sum = 0;
                v.clear();
            }
        }
        if (flag == true) ret++;
        else break;
    }
    
    cout << ret;
    return 0;
}