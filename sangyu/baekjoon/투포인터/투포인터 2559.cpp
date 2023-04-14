#include<iostream>

using namespace std;

int arr[100001];

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}

	//연속된 k일수만큼 합을 구해서 가장 큰값을 구합니다.
	int ans = -210000000;
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += arr[i];
	}


	for (int i = 0; i <= n-k; i++)
	{

		if (sum > ans)
		{
			ans = sum;
		}

		sum += arr[i + k];
		sum -= arr[i];

	}

	cout << ans;
}