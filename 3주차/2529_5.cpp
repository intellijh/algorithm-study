#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
char a[10];
bool visited[10];
vector<string> ret;

bool check(char a, char b, char op) {
    if (op == '>') return a > b;
    else return a < b;
}

void go(int index, string num) {
    if (index == n + 1) {
        ret.push_back(num);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (visited[i]) continue;
        if (index == 0 || check(num[index - 1], i + '0', a[index - 1])) {
            visited[i] = 1;
            go(index + 1, num + to_string(i));
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    go(0, "");
    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << '\n';
    cout << ret[0] << '\n';

    return 0;
}