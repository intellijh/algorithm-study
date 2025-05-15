#include <bits/stdc++.h>
using namespace std;

vector<int> num;
vector<char> op;
string s;
int n;
long long ret = -1e18;

int oper(int a, int b, char c) {
    if (c == '+') return a + b;
    else if (c == '*') return a * b;
    else return a - b;
}

void go(int here, long long _num) {
    if (here == num.size() - 1) {
        ret = max(ret, _num);
        return;
    }

    go(here + 1, oper(_num, num[here + 1], op[here]));

    if (here + 2 < num.size()) {
        int temp = oper(num[here + 1], num[here + 2], op[here + 1]);
        go(here + 2, oper(_num, temp, op[here]));
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) num.push_back(s[i] - '0');
        else op.push_back(s[i]);
    }

    go(0, num[0]);

    cout << ret << '\n';
    return 0;
}