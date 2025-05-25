#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, m;
    cin >> h >> m;
    m -= 45;
    if (m < 0) {
        m = 60 + m;
        h -= 1;
        if (h < 0) h = 23;
    }

    cout << h << " " << m << '\n';
    return 0;
}