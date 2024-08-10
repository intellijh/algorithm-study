#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string mn = "9999999999", mx = ""; 
int k;
int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
char eq[10];

bool op(int a, int b, char c) {
    if (c == '<') return a < b;
    else return a > b;
}

void go(int *a) {
    string ret;
    for (int i = 0; i < k; i++) {
        if (!op(a[i], a[i+1], eq[i])) return;
        ret += to_string(a[i]);
    }
    ret += to_string(a[k]);
    if (atoll(mn.c_str()) > atoll(ret.c_str())) {
        mn = ret;
    }
    if (atoll(mx.c_str()) < atoll(ret.c_str())) {
        mx = ret;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> k;
    for (int i = 0; i < k; i++) cin >> eq[i];

    do {
        go(a);
    } while (next_permutation(a, a + 10));
    cout << mx << '\n';
    cout << mn << '\n';
    return 0;
}