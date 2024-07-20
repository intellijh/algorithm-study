#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[] = {1, 2, 3};
	bool flag = 1;
	
	do {
		flag = next_permutation(a, a + 3);
		cout << "flag " << flag << '\n';
		for (int i : a) cout << i << ' ';
		cout << '\n';
	} while(flag);
}
