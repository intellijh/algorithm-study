#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
char a[14];
int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
bool flag;
string s, mn = "9999999999", mx = "0000000000";

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    do {
        s = "";
        flag = false;   

        for (int i = 0; i < n; i++) {
            if (a[i] == '<') {
                if (num[i] > num[i + 1]) {
                    flag = true;
                }
            } else {
                if (num[i] < num[i + 1]) {
                    flag = true;
                }
            }

            if (flag) break;
            s += to_string(num[i]);
            if (i == n - 1) {
                s += to_string(num[i + 1]);
            }
        }

        if (flag) continue;
        else {
            for (int i = 0; i < n + 1; i++) {
                if (mn[i] > s[i]) {
                    mn = s;
                    break;
                } else if (mn[i] < s[i]) {
                    break;
                }
            }

            for (int i = 0; i < n + 1; i++) {
                if (s[i] > mx[i]) {
                    mx = s;
                    break;
                } else if (s[i] < mx[i]) {
                    break;
                }
            }
        }
    } while (next_permutation(num, num + 10));

    cout << mx << '\n';
    cout << mn << '\n';

    return 0;
}