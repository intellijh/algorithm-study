#include <bits/stdc++.h>
using namespace std;

int H, W, ret[104][104];
char temp;

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});

    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        int nx = x + 1;
        if (nx >= W) continue;
        if (ret[y][x] != -1 && ret[y][nx] != 0) ret[y][nx] = ret[y][x] + 1;
        q.push({y, nx});
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> temp;
            if (temp != 'c') ret[i][j] = -1;
        }
    }

    for (int i = 0; i < H; i++) {
        bfs(i, 0);
        for (int j = 0; j < W; j++) {
            cout << ret[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}