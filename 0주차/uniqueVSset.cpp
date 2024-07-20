#include <bits/stdc++.h>
using namespace std;

void A() {
	vector<int> v;
	int n = 1e5;
	for (int i = 1; i < n; i++) {
		v.push_back(i);
		v.push_back(n - i);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}

void B() {
	vector<int> v;
	int n = 1e5;
	for (int i = 1; i < n; i++) {
		v.push_back(i);
		v.push_back(n - i);
	}
	set<int> st;
	for (int i : v) {
		st.insert(i);
	}
	vector<int> nv;
	for (int i : st) {
		nv.push_back(i);
	}
}

void test_latency(size_t iteration) {
	PROFILE_START("A");
	A();
	PROFILE_STOP("A");
	PROFILE_START("B");
	B();
	PROFILE_STOP("B");
}
	
int main() {
	const size_t warmups = 1000;
	const size_t tests = 100;
	
	PROFILE_RUN_ALL(warmups, test, test_latency(__loop););
	
	return 0;
}
