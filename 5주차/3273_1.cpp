#include <bits/stdc++.h>
using namespace std;

int n, x, l, r, ret;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> x;
    sort(v.begin(), v.end());

    l = 0; r = v.size() - 1;
    
    while (l < r) {
        if (v[l] + v[r] == x) {
            ret++;
            r--;
        }
        else if (v[l] + v[r] > x) r--; 
        else l++;
    }

    if (n == 1 && v[0] == x) cout << 1 << '\n';
    else cout << ret << '\n';
    return 0;
}