#include <bits/stdc++.h>
using namespace std;

int t, n, m, temp, l, r, mid;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> t;
    while (t--) {
        vector<int> a;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> temp;

            bool flag = 0;
            l = 0; r = a.size() - 1;
            while (l <= r) {
                mid = (l + r) / 2;
                if (a[mid] == temp) {
                    flag = 1;
                    break;
                } 
                else if (a[mid] > temp) r = mid - 1;
                else l = mid + 1;
            }
            if (flag) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }

    return 0;
}