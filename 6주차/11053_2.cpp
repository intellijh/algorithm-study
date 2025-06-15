#include <bits/stdc++.h>
using namespace std;
#define prev ppp

int lis[1004], n, num, len;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto lower_pos = lower_bound(lis, lis + len, num);
        if (*lower_pos == 0) len++;
        *lower_pos = num;
    }

    cout << len << '\n';
    return 0;
}