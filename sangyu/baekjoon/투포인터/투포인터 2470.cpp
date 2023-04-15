#include<iostream>
#include<algorithm>
using namespace std;

int n;
long arr[100001];
int minNum=2000000001;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int st = 0, en = n - 1;
	bool findans = false;
	pair<int, int> ans;
	sort(arr, arr + n);

	while (st< en)
	{
		
		if (minNum > abs(arr[st] + arr[en]))
		{
			minNum = abs(arr[st] + arr[en]);
			ans = { arr[st],arr[en] };
		
			if (abs(arr[st] + arr[en]) == 0)
				break;

		}

		
		if (arr[st] + arr[en] < 0)
			st++;
		else
			en--;
	}

	cout << ans.first << ' ' << ans.second;
}