#include <bits/stdc++.h>
using namespace std;

int n, k, ret = 987654321, here;
int visited[100004], cnt[100004];
queue<int> q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    
    if (n == k) {
        cout << 0 << '\n';
        cout << 1 << '\n';
        return 0;
    }

    cnt[n] = 1;
    q.push(n);
    while (q.size()) {
        here = q.front(); q.pop();

        for (int next : {here - 1, here + 1, here * 2}) {
            if (0 <= next && next <= 100000) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = visited[here] + 1;
                    cnt[next] += cnt[here];
                } else if (visited[next] == visited[here] + 1) {
                    cnt[next] += cnt[here];
                }
            }
        }
    }

    cout << visited[k] << '\n';
    cout << cnt[k] << '\n';

    return 0;
}