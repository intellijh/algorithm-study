#include <bits/stdc++.h>
using namespace std;

int ret, n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 666;; i++) {
        if (to_string(i).find("666") == string::npos) continue;
        if (--n == 0) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}