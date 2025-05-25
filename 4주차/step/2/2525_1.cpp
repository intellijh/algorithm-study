#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, h, m;
    cin >> a >> b >> c;
    
    h = c / 60;
    m = c % 60;
    a = ((a + h) + (b + m) / 60) % 24 ; 
    b = (b + m) % 60;

    cout << a << " " << b << '\n';
    return 0;
}