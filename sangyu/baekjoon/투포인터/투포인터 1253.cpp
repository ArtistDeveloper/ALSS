#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[2001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);


	int ans = 0;

	//���� ���� ã������ �ٽ� ó������ ã�ƾ���.
	for (int i = 0; i < n; i++)
	{
		int st = 0;
		int en = n-1;
		while (st<en)
		{
			if (arr[i] == arr[st] + arr[en])
			{
				if (st != i && en != i)
				{
					ans++;
					break;
				}
				else if (st == i)
					st++;
				else if (en == i)
					en--;
			}
			else if (arr[i] > arr[st] + arr[en])
				st++;
			else
				en--;
		}

	}

	cout << ans;
}