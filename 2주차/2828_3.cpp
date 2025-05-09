#include <bits/stdc++.h>
using namespace std;

int a[24];
int n, m, j, ret, st, ed;

void go(int idx) {
    while (true) {
        if (st <= idx && idx <= ed) {
            return;
        } else if (st > idx) {
            ret++;
            st--;
            ed--;
        } else {
            ret++;
            st++;
            ed++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> j;
    for (int i = 0; i < j; i++) {
        cin >> a[i];
    }

    st = 1;
    ed = m;
    
    for (int i = 0; i < j; i++) {
        go(a[i]);
    }


    cout << ret << '\n';

    return 0;
}