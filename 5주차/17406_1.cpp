#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
struct R {
    int a, b, c;
};
int n, m, k, ret = INF, a[54][54], b[54][54], r, c, s;
vector<int> temp, t;
vector<pair<int, int>> vv;

void rotate(int r, int c, int s) {
    while (s > 0) {
        int y = r - s, x = c - s;
        int di = 1;

        t.clear(); vv.clear();
        vv.push_back({y, x});
        while (true) {
            int ny = y + dy[di];
            int nx = x + dx[di];
            if (ny == r - s && nx == c - s) break;
            if (ny < r - s || nx < c - s || ny > r + s || nx > c + s) {
                di = (di + 1) % 4;
                ny = y + dy[di];
                nx = x + dx[di];
            }
            if (ny == r - s && nx == c - s) break;
            vv.push_back({ny, nx});
            y = ny; x = nx;
        }

        for (auto it : vv) t.push_back(b[it.first][it.second]);
        rotate(t.rbegin(), t.rbegin() + 1, t.rend());
        for (int i = 0; i < t.size(); i++) {
            b[vv[i].first][vv[i].second] = t[i];
        }

        s--;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<R> v;
    for (int i = 0; i < k; i++) {
        cin >> r >> c >> s; r--; c--;
        v.push_back({r, c, s});
        temp.push_back(i);
    }

    do {
        //순환
        memcpy(b, a, sizeof(a));
        for (int i = 0; i < k; i++) {
            R r = v[temp[i]];
            rotate(r.a, r.b, r.c);
        }
        
        //계산
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += b[i][j];
            }
            ret = min(ret, sum);
        }
    } while (next_permutation(temp.begin(), temp.end()));

    cout << ret << '\n';
    return 0;
}