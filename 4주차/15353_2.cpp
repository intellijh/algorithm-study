#include <bits/stdc++.h>
using namespace std;

string a, b, ret;
int sum;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> a >> b;

    while (a.size() || b.size() || sum) {
        if (a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (b.size()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        
        ret += sum % 10 + '0';
        sum /= 10;
    }

    reverse(ret.begin(), ret.end());
    cout << ret << '\n';

    return 0;
}