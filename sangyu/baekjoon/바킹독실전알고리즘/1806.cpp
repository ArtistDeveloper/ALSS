#include<iostream>
#include<algorithm>

using namespace std;

int n,s;
int arr[100001];
int main()
{
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int ans = 100001;
	int en = 0;
	int sum = arr[0];
	for(int st = 0; st<n; st++) // 최대 N시간임. 
	{
		while (sum < s && en < n)
		{
			
			en++;
			if(en!=n)
			sum += arr[en];
			
		}
		if (en == n) break;
		ans = min(ans, en-st+1);
		sum -= arr[st];
	}
	if (ans == 100001)
		ans = 0;
	cout << ans;
}