#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	string s;
	cin >> n >> q >> s;
	vector<int> prefix_sum(n, 0);
	// use the concept of prefix sum
	prefix_sum[0] = s[0] - 'a' + 1;
	for (int i = 1; i < n; i++) {
		prefix_sum[i] = prefix_sum[i - 1] + (s[i] - 'a' + 1);
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		// calculate the difference between the value at the 'r'-th minus one index and
		// the value at the 'l'-th minus two index (if possible)
		// the 'minus two part' in the 'l' index is derived from ('l' - 1 - 1), the first
		// 'minus one' is the correcting the index position and the second 'minus one' is
		// for including the value at the index of 'l' minus one because it is inclusive
		// to calculate the sum
		cout << prefix_sum[r - 1] - ((l - 2) >= 0 ? prefix_sum[l - 2] : 0) << '\n';
	}
	return 0;
}
