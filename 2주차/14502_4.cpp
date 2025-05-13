#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, ret, a[66][66], temp[66][66];
bool visited[66][66];
vector<pair<int, int>> v, s;

void dfs(int y, int x) {
    visited[y][x] == 1;
    temp[y][x] = 2;    

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (temp[ny][nx] != 0 || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) v.push_back({i, j});
            else if (a[i][j] == 0) s.push_back({i, j});
        }
    }
    
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            for (int k = j + 1; k < s.size(); k++) {
                memcpy(temp, a, sizeof(a));
                memset(visited, 0, sizeof(visited));

                temp[s[i].first][s[i].second] = 1;
                temp[s[j].first][s[j].second] = 1;
                temp[s[k].first][s[k].second] = 1;
                
                for (auto it : v) {
                    dfs(it.first, it.second);
                }
            
                int cnt = 0;
                for (int i = 0 ; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (temp[i][j] == 0) cnt++;
                    }
                }
                ret = max(cnt, ret);
            }
        }
    }

    cout << ret << '\n';

    return 0;
}