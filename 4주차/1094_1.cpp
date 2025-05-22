#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

void go() {
    int sum = 0;
    for (int i : v) sum += i;

    if (sum == n) return;
    
    int temp = v[v.size() - 1];
    if (sum - temp / 2 >= n) {
        v.pop_back();
        v.push_back(temp / 2);
    } else {
        v.pop_back();
        v.push_back(temp / 2);
        v.push_back(temp / 2);
    }
    go();
} 

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    v.push_back(64);
    go();

    cout << v.size() << '\n';

    return 0;
}