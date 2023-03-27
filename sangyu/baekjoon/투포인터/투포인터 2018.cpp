#include<iostream>

using namespace std;

int n;

int main()
{
	cin >> n;

	int st = 1, en = 1;
	int sum=0;
	int ans = 0;

	while (st<=n && en <= n)
	{
		if (sum < n)
		{
			sum += en;
			en++;
		}
		else
		{
			if (sum == n)
			{
				ans++;
			}
			sum -= st;
			st++;
		}
	}
	cout << ans+1;
}