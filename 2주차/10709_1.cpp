#include <bits/stdc++.h>
using namespace std;

int H, W, a[104][104], ret[104][104];
char temp;

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    if (a[y][x] == 1) ret[y][x] = 0;

    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        int nx = x + 1;
        if (nx >= W) continue;
        if (a[y][nx] == 1) ret[y][nx] = 0;
        else if (ret[y][x] != -1) {
            ret[y][nx] = ret[y][x] + 1;
        }
        q.push({y, nx});
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> temp;
            if (temp == 'c') a[i][j] = 1;
        }
    }

    fill(&ret[0][0], &ret[0][0] + 104 * 104, -1);
    for (int i = 0; i < H; i++) {
        bfs(i, 0);
        for (int j = 0; j < W; j++) {
            cout << ret[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}