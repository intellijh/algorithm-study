#include <bits/stdc++.h>
using namespace std;

const int MAX = 500000;

bool flag;
int n, k, visited[2][MAX + 4], cnt = 1;

void bfs(int here) {
    queue<int> q;
    q.push(here);
    visited[0][here] = 1;

    while (!q.empty()) {
        k += cnt;

        if (k > MAX) break;
        if (visited[cnt % 2][k]) {
            flag = true;
            return;
        }

        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            here = q.front(); q.pop();

            for (int next : {here - 1, here + 1, here * 2}) {
                if (next < 0 || next > MAX || visited[cnt % 2][next]) continue;
                if (k == next) {
                    flag = true;
                    return;
                }
                visited[cnt % 2][next] = visited[(cnt + 1) % 2][here] + 1;
                q.push(next);
            }
        }

        cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k;

    if (n == k) {
        cout << 0 << '\n';
        return 0;
    }

    bfs(n);
    if (flag) cout << cnt;
    else cout << -1;
    return 0;
}