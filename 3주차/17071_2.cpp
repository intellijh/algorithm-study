#include <bits/stdc++.h>
using namespace std;

int n, k, here, turn = 1;
queue<int> q;
int visited[2][500004];
bool flag;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    if (n == k) {
        cout << 0 << '\n';
        return 0;
    }

    q.push(n);
    visited[0][n] = 1;
    while (q.size()) {
        k += turn;
        
        if (k > 500000) break;

        if (visited[turn % 2][k]) {
            flag = true;
            break;
        }
        
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            here = q.front(); q.pop();

            for (int next : {here - 1, here + 1, here * 2}) {
                if (0 <= next && next <= 500000) {
                    if (next == k) {
                        flag = true;
                        break;
                    }

                    if (!visited[turn % 2][next]) {
                        q.push(next);
                        visited[turn % 2][next] = visited[(turn + 1) % 2][here] + 1;
                    }

                }
            }
            if (flag) break;
        }
        if (flag) break;

        turn++;
    }

    if (flag) cout << turn << '\n';
    else cout << -1 << '\n';

    return 0;
}