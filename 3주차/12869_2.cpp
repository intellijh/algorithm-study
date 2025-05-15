#include <bits/stdc++.h>
using namespace std;

struct Scv {
    int a, b, c;
};

queue<Scv> q;
int n, ret = 987654321;
int v[3];
int a[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 3, 9},
    {1, 9, 3}
};
int visited[64][64][64];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    Scv scv = {v[0], v[1], v[2]};
    visited[scv.a][scv.b][scv.c] = 1;
    q.push(scv);
    while (q.size()) {
        scv = q.front(); q.pop();

        if (visited[0][0][0]) {
            ret = visited[0][0][0] - 1;
            break;
        }
        for (int i = 0; i < 6; i++) {
            Scv scv2;
            scv2.a = max(0, scv.a - a[i][0]);
            scv2.b = max(0, scv.b - a[i][1]);
            scv2.c = max(0, scv.c - a[i][2]);

            if (visited[scv2.a][scv2.b][scv2.c]) continue;
            visited[scv2.a][scv2.b][scv2.c] = visited[scv.a][scv.b][scv.c] + 1;
            q.push(scv2);
        }
    }

    cout << ret << '\n';

    return 0;
}