#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, temp;
    cin >> a >> b >> c;

    if (a == b && b == c) cout << 10000 + a * 1000 << '\n';
    else if (a == b && b != c) cout << 1000 + (a * 100) << '\n';
    else if (a != b && b == c) cout << 1000 + (b * 100) << '\n';
    else if (a == c && b != c) cout << 1000 + (a * 100) << '\n';
    else {
        temp = max(a, b);
        temp = max(temp, c);
        cout << temp * 100 << '\n';
    }

}