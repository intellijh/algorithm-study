#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree;

int sum(int index) {
    int ret = 0;
    while (index > 0) {
        ret += tree[index];
        index -= index & -index;
    }
    return ret;
}

void update(int index, int value) {
    while (index <= n) {
        tree[index] += value;
        index += index & -index;
    }
}

int rangeQuery(int start, int end) {
    return sum(end) - sum(start - 1);
}

int main() {
    vector<int> data = {3, 4, 10, 11};
    n = data.size();
    tree.resize(n + 1, 0);

    for (int i = 0; i < n; i++) {
        update(i + 1, data[i]);
    }

    cout << rangeQuery(1, 4) << '\n';
    cout << rangeQuery(2, 3) << '\n';
    update(2, 5);
    cout << rangeQuery(1, 4) << '\n';
    cout << rangeQuery(2, 3) << '\n';

    return 0;
}