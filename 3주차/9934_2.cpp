#include <bits/stdc++.h>
using namespace std;

int n, l, r, mid;
int a[1030];
vector<int> ret;
queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < pow(2, n) - 1; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[0] << '\n';
        return 0;
    }

    q.push({0, pow(2, n) - 2});
    while (q.size()) {
        tie(l, r) = q.front(); q.pop();
        mid = (l + r) / 2;
        ret.push_back(a[mid]);
        if (l == r) continue;

        q.push({l, mid - 1});
        q.push({mid + 1, r});
    }
    
    int cnt = 1;
    for (int i = 0; i < pow(2, n) - 1; i++) {
        cout << ret[i] << " ";
        if ((i + 1) == (pow(2, cnt) - 1)) {
            cout << '\n';
            cnt++;
        }
    }

    return 0;
}