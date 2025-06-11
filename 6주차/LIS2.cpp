#include <bits/stdc++.h>
using namespace std;
#define prev ppp

int n, a[1001], cnt[1001], prev[1001], ret, idx;
vector<int> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    fill(prev, prev + 1001, -1);
    fill(cnt, cnt + 1001, 1);
    for (int i = 0; i < n; i++) {
        int maxValue = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
                prev[i] = j;
                if (ret < cnt[i]) {
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }

    v.push_back(a[idx]);
    while (true) {
        if (prev[idx] == -1) break;
        v.push_back(a[prev[idx]]);
        idx = prev[idx];
    }
    reverse(v.begin(), v.end());
    for (int i : v) cout << i << ' ';

    return 0;
}
