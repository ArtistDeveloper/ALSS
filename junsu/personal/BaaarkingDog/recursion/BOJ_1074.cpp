#include <iostream>

using namespace std;

int count = 0;

// 1. 함수의 정의
// 2. base condition
// 3. 재귀 식

// n = 2일때의 결과를 n = 3에서 써먹을 수 있다.
// n = 3일때의 결과를 n = 4에서 써먹을 수 있다.
// n = k일때의 결과를 n = k + 1에서 써먹을 수 있다.

// 2^n x 2^n 배열에서 (r,c)를 방문하는 순서를 반환하는 함수
int func(int n, int r, int c)
{
	if (n == 0) return 0;
	int half = 1 << (n - 1);

	if (r < half && c < half) return func(n - 1, r, c);
	if (r < half && c >= half) return half * half + func(n - 1, r, c - half);
	if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);
	return 3 * half * half + func(n - 1, r - half, c - half);
	
	func(n, r, c); 
}

int main()
{
	int n, r, c;
	
	cin >> n >> r >> c;
	func(n, r, c);
	cout << func(n, r, c);

	return 0;
}
