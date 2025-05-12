#include <bits/stdc++.h>
using namespace std;

int n, temp, one, two, pre, now, ret1, ret2, t;
string s;

int go() {
    int tt = 0;
    tt += stoi(s.substr(0, 2)) * 60;
    tt += stoi(s.substr(3, 2));
    return tt;
}

void out(int input) {
    printf("%.2d:%.2d\n", input / 60, input % 60);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp; cin >> s;
        if (temp == 1) one++;
        else two++;

        if (pre == 0) {
            pre = one > two ? 1 : 2;
            now = pre;
            t = go();

            if (i == n - 1) {
                s = "48:00";
                if (pre == 1) ret1 += go() - t;
                else ret2 += go() - t;
            }
        } else {
            if (one == two) {
                if (pre == 1) ret1 += go() - t;
                else ret2 += go() - t;
                pre = 0;
            } else {
                if (i == n - 1) {
                    s = "48:00";
                    if (pre == 1) ret1 += go() - t;
                    else ret2 += go() - t;
                }
            }
        }
    }
    
    out(ret1);
    out(ret2);

    return 0;
}