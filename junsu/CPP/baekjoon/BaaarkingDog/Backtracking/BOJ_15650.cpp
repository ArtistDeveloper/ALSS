#include <iostream>

using namespace std;

int arr[10];
bool isUsed[10];
int n, m;

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!isUsed[i])
		{
			// 이전에 입력해둔 숫자가 새로 들어올 숫자보다 작아야 백트래킹 수행. (오름차순)
			if (arr[k - 1] <= i) 
			{
				arr[k] = i;
				isUsed[i] = true;
				func(k + 1);
				isUsed[i] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	func(0);

	return 0;
}
