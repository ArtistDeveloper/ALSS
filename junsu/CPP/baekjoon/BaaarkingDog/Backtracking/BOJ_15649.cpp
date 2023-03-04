#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

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
			arr[k] = i;
			isUsed[i] = true;
			func(k + 1);
			isUsed[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	func(0);

	return 0;
}
