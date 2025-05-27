#include <bits/stdc++.h>
using namespace std;

int n, temp;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (temp != 0) {
            if (v[i].first < temp) {
                v[i].first = temp;
            }
        }
        temp = v[i].first + v[i].second;
    }

    cout << v[n - 1].first + v[n - 1].second << '\n';

    return 0;
}