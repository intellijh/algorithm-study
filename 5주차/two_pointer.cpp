#include <bits/stdc++.h>
using namespace std;

int n, x, ret, l, r;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    sort (a.begin(), a.end());

    l = 0, r = n - 1;
    while (l < r) {
        if (a[l] + a[r] == x) r--, ret++;
        else if (a[l] + a[r] < x) l++;
        else if (a[l] + a[r] > x) r--;
    }

    cout << ret << '\n';

    return 0;
}