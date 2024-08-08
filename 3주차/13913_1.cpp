#include <bits/stdc++.h>
using namespace std;

#define prev aaa
const int MAX = 200000;
int n, k, visited[MAX + 4], prev[MAX + 4];
vector<int> ret;

void bfs(int here) {
    queue<int> q;
    q.push(here);
    visited[here] = 1;
    
    while (!q.empty()) {
        here = q.front(); q.pop();

        if (here == k) break;
        for (int next : {here -1, here + 1, here * 2}) {
            if (0 <= next && next <= MAX) {
                if (!visited[next]) {
                    q.push(next);
                    prev[next] = here;
                    visited[next] = visited[here] + 1;
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
        cout << n << '\n';
        return 0;
    }

    bfs(n);
    for (int i = k; i != n; i = prev[i]) {
        ret.push_back(i);
    }
    ret.push_back(n);
    reverse(ret.begin(), ret.end());
    cout << visited[k] - 1 << '\n';
    for (int i : ret) cout << i << " ";
    return 0;
}