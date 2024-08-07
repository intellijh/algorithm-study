#include <bits/stdc++.h>
using namespace std;

int N, scv[3], visited[64][64][64];
int _a[6][3] = 
{
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 3, 9},
    {1, 9, 3}
};

struct A {
    int a, b, c;
};

int bfs(int a, int b, int c) {
    queue<A> q;
    q.push({a, b, c});
    visited[a][b][c] = 1;

    while (q.size()) {
        a = q.front().a;
        b = q.front().b;
        c = q.front().c;
        q.pop();
        if (visited[0][0][0]) {
            return visited[0][0][0] - 1;
        }
        for (int i = 0; i < 6; i++) {
            int na = max(0, a - _a[i][0]);
            int nb = max(0, b - _a[i][1]);
            int nc = max(0, c - _a[i][2]);
            if (visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na, nb, nc});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> scv[i];
    }
    
    cout << bfs(scv[0], scv[1], scv[2]);
    return 0;
}