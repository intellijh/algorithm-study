#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	cout << gcd(5, 10) << '\n';
	cout << lcm(5, 10) << '\n';
	return 0;
}
