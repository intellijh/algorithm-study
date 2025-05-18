#include <bits/stdc++.h>
using namespace std;
#define y1 yyy

const int dy[] = {0, -1, 0, 1, 0};
const int dx[] = {0, 0, 1, 0, -1};
const int INF = 987654321;
int n, a[14][14], ret = INF, y1, y2, y3, x1, x2, x3;
bool visited[14][14];
vector<pair<int, int>> v;

int check(vector<pair<int, int>>& v) {
    int sum = 0;
    for (auto it : v) {
        if (it.first <= 0 || it.first >= n - 1 || it.second <= 0 || it.second >= n -1) return INF;

        for (int i = 0; i < 5; i++) {
            int ny = it.first + dy[i];
            int nx = it.second + dx[i];

            if (visited[ny][nx]) return INF;
            visited[ny][nx] = 1;
            sum += a[ny][nx];
        }
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n * n; i++) {
        for (int j = i + 1; j < n * n; j++) {
            for (int k = j + 1; k < n * n; k++) {
                memset(visited, 0, sizeof(visited));
                v.clear();
                v.push_back({i / n, i % n});
                v.push_back({j / n, j % n});
                v.push_back({k / n, k % n});
                ret = min(check(v), ret);
            }
        }
    }

    cout << ret << '\n';

    return 0;
}