#include <bits/stdc++.h>
using namespace std;

int a[9];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
	sort(a, a + 9);

	do {
		int sum = 0;
		sum = accumulate(a, a + 7, 0);
		if (sum == 100) break;
	} while (next_permutation(a, a + 9));

	for (int i = 0; i < 7; i++) cout << a[i] << '\n';
	return 0;
}
