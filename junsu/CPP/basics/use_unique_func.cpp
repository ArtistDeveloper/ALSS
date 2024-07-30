#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int main() {
	for (int i = 1; i <= 5; i++) {
		v.push_back(i);
		v.push_back(i);
	}
	
	for (int i : v) cout << i << " ";
	cout << '\n';

	// 고유값을 배열에 넣은 후 남은 값을 중복되지 않은 요소로 채운 후, 
	// 그 다음 위치의 이터레이터를 반환한다.
	auto it = unique(v.begin(), v.end());
	cout << it - v.begin() << '\n';

	for (int i : v) cout << i << ' ';
	cout << '\n';
	return 0;
}

/*
1 1 2 2 3 3 4 4 5 5
5
1 2 3 4 5 3 4 4 5 5
*/


//#include <bits/stdc++.h>
//using namespace std;
//
//vector<int> v{2, 2, 1, 1, 2, 2, 3, 3, 5, 6, 7, 8, 9};
//int main() {
//	sort(v.begin(), v.end());
//	v.erase(unique(v.begin(), v.end()), v.end());
//	for (int i : v) cout << i << ' ';
//	cout << '\n';
//	return 0;
//}
//
///* 1 2 3 5 6 7 8 9 */
