#include<iostream>
#include<queue>
using namespace std;
int n;
int arr[1030][1030];


int minval(int y, int x)
{
	priority_queue<int> pq;
	cout << y << ' ' << x << endl;
	for (int i = y; i < y + 2; i++)
	{
		for (int j = x; j < x + 2; j++)
		{
			pq.push(arr[i][j]);
		}
	}
	pq.pop();
	cout << pq.top()<<endl;
	return pq.top();
}

//재귀로 가지 않아도 될듯?
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>arr[i][j];
		}
	}

	while (n > 1)
	{
		for (int i = 0; i < n; i+=2)
		{
			for (int j = 0; j < n; j+=2)
			{
				arr[i / 2][j / 2] = minval(i, j);
			}
		}
		n= n/2;
	}

	cout << arr[0][0] << endl;
}