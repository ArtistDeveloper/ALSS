#include <bits/stdc++.h>

using namespace std;

vector<int> v = { 1, 2, 3 };

void printV(vector<int> v) {
	for (int val : v) cout << val << " ";
	cout << '\n';
}

void makePermuation(int n, int r, int depth) {
	cout << n << " : " << r << " : " << depth << '\n';

	if (r == depth) {
		printV(v);
	}

	for (int i = depth; i < n; i++) {
		swap(v[i], v[depth]);
		makePermuation(n, r, depth + 1);
		swap(v[i], v[depth]);
	}

	return;
}

int main() {
	makePermuation(3, 3, 0);
	return 0;
}
