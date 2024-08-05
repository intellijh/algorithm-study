#include <bits/stdc++.h>
using namespace std;

int N, temp, d, ret, root;
vector<int> v[54];

void pre_order(int idx) {
    if (idx == d) return;
    if (!v[idx].size()) {
        ret++;
        return;
    }

    for (int i : v[idx]) {
        if (v[idx].size() == 1) {
            if (i == d) {
                ret++;
                continue;
            }
        }
        pre_order(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp == -1) {
            root = i;
            continue;
        }
        v[temp].push_back(i);
    }
    cin >> d;
    v[d].clear();

    pre_order(root);
    cout << ret;
    return 0;
}