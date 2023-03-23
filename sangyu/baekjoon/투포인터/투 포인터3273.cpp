#include<iostream>
#include<algorithm>

using namespace std;
int n;
int arr[100005];
int x;

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	cin >> x;

	sort(arr, arr + n);

	int en = n-1;
	int st = 0;
	int ans = 0;
	while (st<en)
	{

		if (arr[st] + arr[en] == x)
		{
			ans++;
			st++;
			en--;
		}
		else if (arr[st] + arr[en] < x)
		{
			st++;
		}
		else
		{
			en--;
		}
	}
	cout << ans;
	
}