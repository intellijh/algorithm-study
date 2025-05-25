#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    string s;
    if (a >= 90) s = "A";
    else if (a >= 80) s = "B";
    else if (a >= 70) s = "C";
    else if (a >= 60) s = "D";
    else s = "F";
    cout << s << '\n';
    return 0;
}