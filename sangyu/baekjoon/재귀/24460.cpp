#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int arr[1030][1030]; //2^10�� �ִ�.
vector<int> a;
int solve(int y, int x, int size)
{
	vector<int> minarr;

	if (size == 1)
	{
		//�ι�°�� ���� ���� ��Ե˴ϴ�.
		return arr[y][x];
	}	
	else
	{
		int new_size = size / 2;
		//��������� �ݺ��մϴ�.
		minarr.push_back(solve(y, x, new_size)); //1��и�
		minarr.push_back(solve(y, x + new_size, new_size)); //2��и�
		minarr.push_back(solve(y + new_size, x, new_size));//3��и�
		minarr.push_back(solve(y + new_size, x + new_size, new_size));//4�и�
		
	
		sort(minarr.begin(), minarr.end(), less<int>());
		return minarr[1];
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout<< solve(0, 0, n);
}