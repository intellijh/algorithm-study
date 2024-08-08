#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int n, k, cnt[MAX + 4], visited[MAX + 4];

void bfs(int num) {
    queue<int> q;
    q.push(num);
    visited[num] = 1;
    cnt[num] = 1;

    while (!q.empty()) {
        num = q.front(); q.pop();
        for (int next : {num -1, num + 1, num * 2 }) {
            if (0 <= next && next <= MAX) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = visited[num] + 1;
                    cnt[next] += cnt[num];
                } else if (visited[next] == visited[num] + 1) {
                    cnt[next] += cnt[num];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k;

    if (n == k) {
        cout << 0 << '\n';
        cout << 1 << '\n';
        return 0;
    }
    bfs(n);
    cout << visited[k] - 1 << '\n';
    cout << cnt[k] << '\n';
    return 0;
}