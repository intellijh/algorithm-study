#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string s;
    if (a > b) s = ">";
    else if (a < b) s = "<";
    else s = "==";

    cout << s << '\n';

    return 0;
}