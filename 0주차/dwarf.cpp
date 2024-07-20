#include <bits/stdc++.h>
using namespace std;

int n = 9;
vector<int> input;

int main() {
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		input.push_back(temp);
	}
	
	sort(input.begin(), input.end());
	
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = 0;
			
			for (int k : input) {
				if (k != input[i] && k != input[j]) sum += k;
			}
			if (sum == 100) {
				for (int k : input) {
					if (k != input[i] && k != input[j]) temp.push_back(k);
				}
				break;
			}
		}
	}
	
	 cout << "Size of temp vector: " << temp.size() << '\n';
	
	for (int i : temp) cout << i << '\n';
	return 0;
}
