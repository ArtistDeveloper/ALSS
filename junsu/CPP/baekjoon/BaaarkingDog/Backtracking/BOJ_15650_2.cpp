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
	}

	int start = 1;
	// 이를 통해 다음에 올 숫자가 이전 숫자보다 작을 수 없으므로 오름차순이 형성된다.
	if (k != 0) start = arr[k - 1] + 1; 

	for (int i = start; i <= n; i++)
	{
		if (!isUsed[i])
		{
			arr[k] = i;
			isUsed[i] = true;
			func(k + 1);
			isUsed[i] = false;
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
