#include <bits/stdc++.h>
using namespace std;

int n;
double a[10004], ret, cur = 1.0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cur *= a[i];
        
        if (cur < a[i]) cur = a[i];
        ret = max(ret, cur);
    }

    cout << fixed << setprecision(3) << ret << '\n';

    return 0;
}