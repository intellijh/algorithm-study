#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y, z;
	
	Point(int x, int y, int z) : y(y), x(x), z(z) {}
	Point() {y = -1; x = -1; z = -1;}
	bool operator < (const Point &a) const {
		if (x == a.x) {
			if (y == a.y) return z < a.z;
			return y > a.y;
		}
		return x < a.x;
	}
};

int main() {
	Point a[3] = {{1, 1, 5}, {1, 2, 3}, {2, 3, 2}};
	sort(a, a + 3);
	for (Point A : a) cout << A.x << " : " << A.y << " : " << A.z << '\n';
	return 0;
}
