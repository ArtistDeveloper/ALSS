// 오름차순을 기반으로 순열을 만든다. 따라서 배열의 수가 오름차순으로 정렬되어 있어야 한다.

#include <bits/stdc++.h>

using namespace std;

int main() {
	int a[] = { 1, 2, 3 };
	vector<int> b = { 1, 2, 3 };
	vector<int> c = { 2, 1, 3, 100, 200 };

	sort(c.begin(), c.end());

	do {
		for (int i : a) cout << i << " ";
		cout << '\n';
	} while (next_permutation(a, a + 3));
	
	cout << '\n';

	do {
		for (int i : b) cout << i << " ";
		cout << '\n';
	} while (next_permutation(b.begin(), b.end()));

	
	// 5개 중 2개를 뽑기
	do {
		for (int i = 0; i < 2; i++){
			cout << c[i] << " ";
		}
		cout << '\n';
	} while (next_permutation(c.begin(), c.end()));

	return 0;
}
