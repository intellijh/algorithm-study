#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int caseNum;
	cin >> caseNum;
	
	for (int i = 0; i < caseNum; i++) {
		int N;
		cin >> N; 
		vector<int> v1;
		
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			v1.push_back(num);
		}
		
		int M;
		cin >> M;
		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			int n = 0;
			for (int j : v1) {
				if (j == num) {
					n = 1;
					break;
				}
			}
			cout << n << '\n';
		}
		
	}
	return 0;
}
