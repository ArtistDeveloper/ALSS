#include<iostream>

using namespace std;

long long n, m;
long long arr[10005];
int cnt = 0;
int main()
{
	cin >> n >> m;


	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int st = 0, en = 0, sum = 0;

	while (en <= n)
	{
		if (sum < m)
		{
			sum += arr[en];
			en++;
		}
		if (sum >= m)
		{
			if (sum == m)
			{
				cnt++;
			}
			sum -= arr[st];
			st++;
		}
	}

	cout << cnt;
}