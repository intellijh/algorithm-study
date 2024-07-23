#include <bits/stdc++.h>
using namespace std;

string input;
string r;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> input;
    r = input;
    reverse(r.begin(), r.end());

    if (r == input) cout << 1;
    else cout << 0;

    return 0;
}