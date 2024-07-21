#include <bits/stdc++.h>
using namespace std;

vector<int> dw;
vector<int> rdw;
int total;
bool found = false;

int main() {
	int num;
	for (int i = 0; i < 9; i++) {
		cin >> num;
		dw.push_back(num);
	}
	sort(dw.begin(), dw.end());
	total = accumulate(dw.begin(), dw.end(), 0);

	int temp = 0;
	for (int i = 0; i < 9 && !found; i++) {
		for (int j = i + 1; j < 9 && !found; j++) {
			temp = total - dw[i] - dw[j];
			if (temp != 100) {
				continue;
			}

			found = true;
			for (int k = 0; k < 9; k++) {
				if (k == i || k == j) continue;
				rdw.push_back(dw[k]);
			}
		}
	}

	for (int i : rdw) {
		cout << i << '\n';
	}
	return 0;
}
