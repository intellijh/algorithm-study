#include <bits/stdc++.h>
using namespace std;

int n;
double a[10004], ret;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        double cur = 1.0;
        for (int j = i; j < n; j++) {
            cur *= a[j];
            ret = max(ret, cur);
        }
    }

    printf("%.3lf\n", ret);

    return 0;
}