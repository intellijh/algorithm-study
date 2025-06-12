#include <bits/stdc++.h>
using namespace std;

int n, m, temp, l, r, mid, cnt;
vector<int> a, b;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
        cin >> temp;
        b.push_back(temp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        l = 0; r = m - 1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (b[mid] == a[i]) {
                cnt++;
                break;
            } else if (b[mid] > a[i]) {
                r = mid -1;
            } else {
                l = mid + 1;
            }
        }
    }

    cout << (n + m) - (2 * cnt) << '\n';

    return 0;
}