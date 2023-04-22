#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	int arr[15001];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int st = 0, ans=0, en = n - 1;
	while (st < en)
	{
		int sum = arr[st] + arr[en];
		if (sum == m)
		{
			ans++;
			st++;
			en--;
		}
		if (sum < m)
			st++;
		if (sum > m)
			en--;
	}

	cout << ans<<'\n';

}

