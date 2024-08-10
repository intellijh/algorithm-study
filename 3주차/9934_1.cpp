#include <bits/stdc++.h>
using namespace std;

int k, a[1030];
vector<int> ret[14];

void go(int s, int e, int level) {
    if (s > e) return;
    if (s == e) {
        ret[level].push_back(a[s]);
        return;
    }
    
    int mid = (s + e) / 2;
    ret[level].push_back(a[mid]);
    go(s, mid -1, level + 1);
    go(mid + 1, e, level + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> k;
    for (int i = 0 ; i < pow(2, k) - 1; i++) cin >> a[i];

    go(0, pow(2, k) - 1, 0);
    for (int i = 0; i < k; i++) {
        for (int j : ret[i]) {
            cout << j << " ";
        }
        cout << '\n';
    }
    return 0;
}