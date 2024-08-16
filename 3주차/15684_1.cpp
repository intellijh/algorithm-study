#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, 1};
const int dx[] = {1, 0};
int N, M, H, ret = 987654321, visited[34][14], a, b;

bool check() {
    for (int i = 1; i <= N; i++) {
        int start = i;
        for (int j = 1; j <= H; j++) {
            if (visited[j][start]) {
                start += 1;
            } else if (visited[j][start - 1]) {
                start -= 1;
            }
        }
        if (start != i) {
            return false;
        }
    }
    return true;
}

void go(int here, int cnt) {
    if (cnt > 3 || cnt >= ret) return;
    if (check()) {
        ret = min(ret, cnt);
        return;
    }

    for (int i = here; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
            visited[i][j] = 1;
            go(i, cnt + 1);
            visited[i][j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        visited[a][b] = 1;
    }

    go(1, 0);
    if (ret > 3) cout << -1;
    else cout << ret;
    return 0;
}