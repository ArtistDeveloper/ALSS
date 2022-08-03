#include <iostream>

using namespace std;

/// n부터 1까지 출력하는 함수
// print(1)은 1이 출력될 것이 자명하다.
// print(k)는 k, k-1, k-2 ... 1을 출력하면 print(k+1)은 k+1, k, k-1 .. 1을 출력한다.
// k+1호출 -> print(k) 호출 = k, k-1, k-2 ... 1출력
// k+1호출을 통해 k+1이 출력되는 것은 자명하다.
// k+1호출을 통해 print(k)가 호출된다. print(k)는 위의 설명에 적혀있는 그대로이다.
// 즉, k+1부터 1까지 출력된다는 사실은 자명하다.
void print(int n)
{
	if (n == 0) return;
	cout << n << ' ';
	print(n - 1);
	// cout << n << ' '; // 여기 넣으면 1, 2, 3출력
}


/// 1부터 n까지의 합을 구하는 함수
// n이 0일 때 0을 돌려준다는 것은 자명하다.
// n + sum(n-1)에서 n이 5라면 5 + 4가 될 것은 자명하다.
// 그러면 그게 반복되어 숫자 1까지 더해질 것은 자명하다.
// 그럼 결론적으로 n부터 1까지의 덧셈이 제대로 수행될 것이다.
int sum(int n)
{
	if (n == 0) return 0;
	return n + sum(n - 1);
}

int main()
{
	cout << sum(5) << '\n';
	print(3);

	return 0;
}