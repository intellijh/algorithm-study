#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int n, from, to, l, r, ret;
P L[1000004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> from >> to;
        L[i] = P(from, to);
    }
    sort(L, L + n);

    l = L[0].first; r = L[0].second;
    for (int i = 1; i < n; i++) {
        if (r < L[i].first) {
            ret += r - l;
            l = L[i].first;
            r = L[i].second;
        } else if (r >= L[i].first && r <= L[i].second) {
            r = L[i].second;
        }
    }
    ret += r - l;

    cout << ret << '\n';

    return 0;
}
