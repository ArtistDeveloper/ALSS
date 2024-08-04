// 문제 생각 //
// 9명 중 7개를 뽑는 것이며, 순서는 상관이 없다. 즉, 조합으로 9c7인 경우이며 총 경우의 개수는 36개이다.
// 이 36개의 케이스에 대해 모두 살펴보면, 모두의 합이 100인 경우를 찾을 수 있을 것이다.

// 풀이 //
// 1. 전체 조합의 경우의 수를 순회한다.
// 2. 9c7 조합에 해당하는 수를 더해서 100이 되면 출력한다. 100이 아니면 다음 경우의 수를 순회한다.

#include <bits/stdc++.h>
#define TARGET 100
#define N 9
#define R 7

using namespace std;

vector<int> v(N);

int accumulate(vector<int> result) {
	int sum = 0;
	for (int val : result) {
		sum += val;
	}
	return sum;
}

void combi(int start, vector<int> result) {
	if (result.size() == R) {
		int total = accumulate(result);

		if (total == TARGET) {
			for (int val : result) {
				cout << val << '\n';
			}
			cout << '\n';
			exit(0);
		}

		return;
	}

	for (int i = start + 1; i < N; i++) {
		result.push_back(v[i]);
		combi(i, result);
		result.pop_back();
	}
	return;
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	vector<int> result;
	combi(-1, result);	
}
