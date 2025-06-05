#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, k, l, ret, a[104][104], di = 1, y, x, idx;
vector<pair<int, int>> v;
deque<pair<int, int>> dq;
bool visited[104][104];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    int t1, t2;
    for (int i = 0; i < k; i++) {
        cin >> t1 >> t2;
        a[t1][t2] = 1;
    }
    cin >> l;
    char temp;
    for (int i = 0; i < l; i++) {
        cin >> t1 >> temp;
        if (temp == 'L') v.push_back({t1, 3});
        else v.push_back({t1, 1});
    }

    dq.push_back({1, 1});
    visited[1][1] = 1;
    while (dq.size()) {
        ret++;
        tie(y, x) = dq.front();
        int ny = y + dy[di];
        int nx = x + dx[di];

        if (ny < 1 || nx < 1 || ny > n || nx > n || visited[ny][nx]) break;
        if (!a[ny][nx]) {
            visited[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        } else a[ny][nx] = 0;

        dq.push_front({ny, nx});
        visited[ny][nx] = 1;

        if (ret == v[idx].first) {
            di = (di + v[idx].second) % 4;
            idx++;
        }
    }

    cout << ret << '\n';

    return 0;
}