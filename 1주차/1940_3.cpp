#include <bits/stdc++.h>
using namespace std;

int n, m, temp, cnt;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    if (m > 200000) cout << 0 << '\n';
    else {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (v[i] + v[j] == m) cnt++;
            }
        }
        cout << cnt << '\n';
    }


    return 0;
}