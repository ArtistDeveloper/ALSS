#include<iostream>

using namespace std;

int n, d, k, c;
int arr[30001*2];
int ateCnt[3001];
int maxCount;
int cnt;
int main()
{
	cin >> n >> d >> k >> c;

	ateCnt[c]++;
	cnt = 1;
	maxCount = 1;

	//n��°���� 1���� Ž���� ��쵵 ����
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		arr[n + i] = arr[i];
	}

	for (int i = 0; i < n +k; i++)
	{
		if (i >= k)
		{
			ateCnt[arr[i - k]]--;
			if (ateCnt[arr[i - k]] == 0)
			{
				cnt--;
			}
		}


		if (ateCnt[arr[i]] == 0)
		{
			cnt++;
			maxCount = max(maxCount, cnt);
		}
		ateCnt[arr[i]]++;
	}

	cout << maxCount;
}