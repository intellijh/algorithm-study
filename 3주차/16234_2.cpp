#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int ret, n, a[54][54], l, r;
bool visited[54][54], flag;
vector<pair<int, int>> p;
vector<int> v;

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx]) continue;
        int temp = abs(a[y][x] - a[ny][nx]);
        if (temp < l || temp > r) continue;
        
        v.push_back(a[ny][nx]);
        p.push_back({ny, nx});
        flag = true;
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    while (true) {
        memset(visited, 0, sizeof(visited));
        flag = false;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    v.clear();
                    p.clear();

                    dfs(i, j);
                    v.push_back(a[i][j]);
                    p.push_back({i, j});

                    int sum = accumulate(v.begin(), v.end(), 0);
                    int average = sum / v.size();

                    for (auto it : p) {
                        a[it.first][it.second] = average;
                    }   
                }
            }
        }

        if (flag == false) break;
        else ret++;
    }
    cout << ret << '\n';

    return 0;
}