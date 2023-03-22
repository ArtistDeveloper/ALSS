#include<iostream>

using namespace std;

int n;
int arr[100001];
bool check[100001];
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//1,2,3,4,5 -> 1,12,123,1234,12345 5°³. en-st =5; 
	long long ans = 0;
	int en = 0;
	for (int st = 0; st < n; st++)
	{
		while (en < n)
		{
			if (check[arr[en]] == true)
				break;

			check[arr[en]] = true;
			en++;
		}
		
		ans += (en - st);
		check[arr[st]] = 0;
		
	}
	cout << ans;

	
}