#include <bits/stdc++.h>
using namespace std;

int a[3] = {1, 2, 3};
int n = 3, r = 3;

void print() {
	for (int i = 0; i < r; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

void makePermutation(int n, int r, int depth) {
	cout << n << " : " << r << " : " << depth << '\n';
	if (r == depth) {
		print();
		return;
	}
	
	for (int i = depth; i < n; i++) {
		cout << i << " : " << depth << "�� �ٲ۴�!\n";
		swap(a[i], a[depth]);
		makePermutation(n, r, depth + 1);
		cout << i << " : " << depth << "�� �ٽ� �ٲ۴�!\n"; 
		swap(a[i], a[depth]);
	}
	return;
}

int main() {
	makePermutation(n, r, 0);
	return 0;
}
