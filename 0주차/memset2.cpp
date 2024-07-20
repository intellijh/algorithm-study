#include <bits/stdc++.h>
using namespace std;

int main() {
	int cnt = 0;
	int a[5] = {0, };
	while (++cnt != 10) {
		for (int i = 0; i <  5; i++) a[i] = i;
		a[5] = {0, };
		for (int i : a)	cout << i << ' ';
	}
	return 0;
}
