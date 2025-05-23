#include <bits/stdc++.h>
using namespace std;

int n, x;
string s;
bool num[21];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    string bufferFlush;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s != "all" && s != "empty") {
            cin >> x;
        }

        if (s == "add") num[x] = 1;
        else if (s == "remove") num[x] = 0;
        else if (s == "check") cout << num[x] << '\n';
        else if (s == "toggle") num[x] = ~num[x];
        else if (s == "all") fill(num, num + 21, 1);
        else if (s == "empty") fill(num, num + 21, 0);
    }

    return 0;
}