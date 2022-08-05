#include <iostream>

using namespace std;

// 1. 함수의 정의: 함수가 어떤 역할을 수행하는지, 어떤 인자를 받는지 정한다.
// 2. base condition: 
// 3. 재귀 식

void hanoi(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << ' ' << b << '\n'; // 원판이 1개라면 원판을 a에서 b로 옮긴다. (이것이 잘 작동하면 n개일 때도 잘 작동하다는 것이 자명하다.)
		return;
	}

	hanoi(a, 6 - a - b, n - 1); // n-1개의 원판까지 1번기둥에서 2번기둥으로 옮김
	cout << a << ' ' << b << '\n'; 
	hanoi(6 - a - b, b, n - 1);  // n-1개를 2번기둥에서 3번기둥으로 옮김
}


int main()
{
	int k;
	cin >> k;
	
	cout << (1 << k) - 1 << '\n';

	hanoi(1, 3, k);

	return 0;
}
