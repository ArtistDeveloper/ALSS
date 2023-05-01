#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000];
int main()
{
	
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			arr[i] = 0;
		}


		int ans = 0;
		for (int i = 2; i = n - 2; i++)
		{
			bool flag=true;
			int maxSt = 0;
			int maxEn = 0;
			for (int st = i - 2; st < i; st++)
			{
				if (arr[i] - arr[st] < 1)
					flag = false;
				else
				{
					maxSt=max(maxSt, arr[st]);
				}
			}
			for (int en = i; en < i+2; en++)
			{
				if (arr[i] - arr[en] < 1)
					flag = false;
				else
				{
					maxEn= max(maxEn, arr[en]);
				}
			}
			if (flag)
			{
				ans+=min(arr[i] - maxSt,arr[i]-maxEn);
			}
		}

		cout << ans<<endl;
	
}