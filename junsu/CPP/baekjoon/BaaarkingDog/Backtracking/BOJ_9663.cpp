#include <iostream>

using namespace std;

bool isUsed1[17]; // 열
bool isUsed2[35]; // 좌측 하단, 우측 상단 연결 대각선 || n의 최대 수 * 2 정도의 범위를 가지면 됨.
bool isUsed3[35]; // 좌측 상단, 우측 하단 연결 대각선 || n의 최대 수 * 2 정도의 범위를 가지면 됨.
int caseCount = 0; // 경우의 수
int n;

// x: 행, y: 열
// cur: 행, i: 열
void func(int cur)
{
	if (cur == n)
	{
		caseCount++;
		return;
	}
	for (int i = 0; i < n; i++) // (cur, i)에 퀸을 놓을 예정
	{
		if (isUsed1[i] || isUsed2[cur + i] || isUsed3[cur - i + n - 1]) 
			continue;

		isUsed1[i] = true;
		isUsed2[cur + i] = true;
		isUsed3[cur - i + n - 1] = true;
		func(cur + 1);
		isUsed1[i] = false;
		isUsed2[cur + i] = false;
		isUsed3[cur - i + n - 1] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	func(0);
	cout << caseCount;

	return 0;
}
