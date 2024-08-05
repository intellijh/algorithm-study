#include <bits/stdc++.h>
using namespace std;

int N, M, a, b, cnt, cntTemp;
int visited[10004];
vector<int> v[10004], ret;

int dfs(int idx) {
    visited[idx] = 1;
    int ret = 1;
    int child = 0;
    for (int i : v[idx]) {
        if (visited[i]) continue;
        ret += dfs(i);
        child++;
    }
    if (child == 0) return 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[0] + 10004, 0);
        int cntTemp = dfs(i);
        if (cnt < cntTemp) {
            ret.clear();
            ret.push_back(i);
            cnt = cntTemp;
        } else if (cnt == cntTemp) {
            ret.push_back(i);
        }
    }
    
    for (int i : ret) {
        cout << i << " ";
    }
    return 0;
}