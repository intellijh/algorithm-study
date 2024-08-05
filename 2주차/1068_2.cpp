#include <bits/stdc++.h>
using namespace std;

int N, temp, d, ret, root;
vector<int> v[54];

int pre_order(int idx) {
    int ret = 0, child = 0;

    for (int i : v[idx]) {
        if (i == d) continue;
        ret+= pre_order(i);
        child++;
    }
    if (child == 0) return 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp == -1) root = i;
        else v[temp].push_back(i);
    }
    cin >> d;
    if (d == root) {
        cout << ret;
        return 0;
    }
    cout << pre_order(root);
    return 0;
}