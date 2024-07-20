#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n = 5;
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += i;
	}
	cout << ret << '\n';
	cout << n * (n + 1) / 2 << '\n';
	return 0;
}
