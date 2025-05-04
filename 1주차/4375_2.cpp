#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while (cin >> n) {
        long long r = 0;
        int cnt = 0;
        while (true) {
            r = (r * 10 + 1) % n;
            cnt++;
            if (r == 0) {
                cout << cnt << '\n';
                break;
            }
        }
    }

    return 0;
}   