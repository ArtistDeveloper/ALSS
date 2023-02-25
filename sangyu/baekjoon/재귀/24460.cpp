#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int arr[1030][1030]; //2^10이 최대.
vector<int> a;
int solve(int y, int x, int size)
{
	vector<int> minarr;

	if (size == 1)
	{
		//두번째로 작은 값을 담게됩니다.
		return arr[y][x];
	}	
	else
	{
		int new_size = size / 2;
		//재귀적으로 반복합니다.
		minarr.push_back(solve(y, x, new_size)); //1사분면
		minarr.push_back(solve(y, x + new_size, new_size)); //2사분면
		minarr.push_back(solve(y + new_size, x, new_size));//3사분면
		minarr.push_back(solve(y + new_size, x + new_size, new_size));//4분면
		
	
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