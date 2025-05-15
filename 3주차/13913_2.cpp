#include <bits/stdc++.h>
using namespace std;

int n, k, here;
queue<int> q;
int visited[100004], pre[100004];
vector<int> ret;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    if (n == k) {
        cout << 0 << '\n';
        cout << n << '\n';
        return 0;
    }

    visited[n] = 1;
    q.push(n);
    while (q.size()) {
        here = q.front(); q.pop();

        for (int next : {here - 1, here + 1, here * 2}) {
            if (0 <= next && next <= 100000) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = visited[here] + 1;
                    pre[next] = here;
                }
            }
        }
    }

    int start = k;
    ret.push_back(start);
    for (int i = 0; i < visited[k] - 1; i++) {
        ret.push_back(pre[start]);
        start = pre[start];
    }
    reverse(ret.begin(), ret.end());

    cout << visited[k] - 1 << '\n';
    for (int i : ret) cout << i << " ";

    return 0;
}