#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[] = {1, 3, 2};
	sort(a, a + 3);
	do {
		for (int i : a) cout << i << " ";
		cout << '\n';
	} while(next_permutation(a, a + 3));
	return 0;
}
