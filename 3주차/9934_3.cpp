#include <bits/stdc++.h>
using namespace std;

int a[1030], n;
vector<int> ret[11];

void go(int l, int r, int level) {
    if (l > r) return;
    if (l == r) {
        cout << level << " " << l << " " <<  r << "\n";
        ret[level].push_back(a[l]);
        return;
    }

    int mid = (l + r) / 2;
    ret[level].push_back(a[mid]);

    go(l, mid - 1, level + 1);
    go(mid + 1, r, level + 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    
    for (int i = 0; i < pow(2, n) - 1; i++) {
        cin >> a[i];
    }

    go(0, pow(2, n) - 1, 0);

    // for (int i = 0; i < n; i++) {
    //     for (int j : ret[i]) {
    //         cout << j << " ";
    //     }
    //     cout << '\n';
    // }

    return 0;
}