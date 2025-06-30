#include <bits/stdc++.h>
using namespace std;

const int N = 39;
int m, f[N + 1] = {0, 5, 13};
string s = "Messi Gimossi";

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> m; m--;

    for (int i = 3; i <= N; i++) {
        f[i] = f[i - 1] + f[i - 2] + 1;
    }

    for (int i = N; i >= 3; i--) {
        if (m >= f[i - 1]) m -= f[i - 1] + 1;
    }

    if (m == 5 || m == -1) cout << "Messi Messi Gimossi\n";
    else cout << s[m] << '\n';
    
    return 0;
}