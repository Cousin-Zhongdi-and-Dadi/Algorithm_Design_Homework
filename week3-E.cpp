#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

bool check(int k, int m) {
	int pos = 0;
	for (int i = 0; i < k; ++i) {
		pos = (pos + m - 1) % (2 * k - i);
		if (pos < k) return false;
	}
	return true;
}

int main() {
	vector<int> ans(14, 0);
	for (int k0 = 1; k0 < 14; ++k0) {
		int m = k0 + 1;
		while (!check(k0, m)) ++m;
		ans[k0] = m;
	}

	int k;
	while ((scanf("%d", &k) != EOF) && k) {
		printf("%d\n", ans[k]);
	}
	return 0;
}
