#include <bits/stdc++.h>

using namespace std;

int n = 5;
int k = 3;

void printV(vector<int> b) {
	for (int i : b) cout << i << "	";
	cout << '\n';
}

void combi(int start, vector<int> b) {
	if (b.size() == k) {
		printV(b);
		return;
	}
	for (int i = start + 1; i < n; i++) {
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
	return;
}


vector<int> permu = {1, 2, 3};
void permutation(int n, int r, int depth) {
	if (depth == r) {
		printV(permu);
		return;
	}

	for (int i = depth; i < n; i++) {
		swap(permu[i], permu[depth]);
		permutation(n, r, depth + 1);
		swap(permu[i], permu[depth]);
	}
	return;
}

void run_permu() {
	permutation(3, 3, 0);
}

void run_combi() {
	vector<int> b;
	combi(-1, b);
}

int main() {
	run_permu();
	return 0;
}
