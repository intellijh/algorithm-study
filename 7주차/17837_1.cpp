#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};

struct M {
    int y, x, d;
};

int n, k, a[14][14];
vector<int> v[14][14];
vector<M> m;
bool flag;

void move(int i) {
    M& mal = m[i];
    int y = mal.y, x = mal.x;
    auto& temp = v[y][x];
    
    int ny = y + dy[mal.d];
    int nx = x + dx[mal.d];

    if (a[ny][nx] == 2 || ny < 0 || nx < 0 || ny >= n || nx >= n) {
        mal.d ^= 1;
        ny = y + dy[mal.d];
        nx = x + dx[mal.d];
        
        if (a[ny][nx] == 2 || ny < 0 || nx < 0 || ny >= n || nx >= n) return;
    }

    vector<int>& here_v = v[y][x];
    vector<int>& next_v = v[ny][nx];

    auto pos = find(here_v.begin(), here_v.end(), i);

    if (a[ny][nx] == 1) {
        reverse(pos, here_v.end());
    }

    for (auto it = pos; it != here_v.end(); it++) {
        next_v.push_back(*it);
        m[*it].y = ny;
        m[*it].x = nx;
    }
    here_v.erase(pos, here_v.end());

    if (v[ny][nx].size() >= 4) flag = true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        int y, x, d;
        cin >> y >> x >> d;
        y--; x--; d--;
        m.push_back({y, x, d});
        v[y][x].push_back(i);
    }

    for (int t = 1; t <= 1001; t++) {
        if (t == 1001) {
            cout << -1 << '\n';
            break;
        }

        for (int i = 0; i < k; i++) {
            move(i);
        }

        if (flag) {
            cout << t << '\n';
            break;
        }
    }



    return 0;
}