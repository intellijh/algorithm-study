#include <bits/stdc++.h>
using namespace std;

string a, b, ret;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    if (a.size() >= b.size()) {
        int temp = 0;
        int i;
        for (i = 0; i < b.size(); i++) {
            if (temp != 0) a[i] += temp;
            temp = (a[i] - '0') + (b[i] - '0');
            ret += to_string(temp % 10);
            temp /= 10;
        }
        
        while (true) {
            if (i >= a.size()) {
                if (temp != 0) ret += to_string(temp);
                break;
            } else {
                if (temp != 0) a[i] += temp;
                temp = a[i] - '0';
                ret += to_string(temp % 10);
                temp /= 10;
            }
            i++;
        }
    } else {
        int temp = 0;
        int i;
        for (i = 0; i < a.size(); i++) {
            if (temp != 0) b[i] += temp;
            temp = (a[i] - '0') + (b[i] - '0');
            ret += to_string(temp % 10);
            temp /= 10;
        }
        
        while (true) {
            if (i >= b.size()) {
                if (temp != 0) ret += to_string(temp);
                break;
            } else {
                if (temp != 0) b[i] += temp;
                temp = b[i] - '0';
                ret += to_string(temp % 10);
                temp /= 10;
            }
            i++;
        }
    }

    reverse(ret.begin(), ret.end());
    cout << ret << '\n';

    return 0;
}