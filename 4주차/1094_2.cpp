#include <bits/stdc++.h>
using namespace std;

int n, ret = 1;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    while (n != 1) {
        if (n & 1) ret++;
        n /= 2;
    }
    cout << ret << '\n';

    return 0;
}