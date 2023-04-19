#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	int n, m;
	vector<int> arrA;
	vector<int> arrB;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arrA.push_back(a);
	}
	for (int i = 0; i < m; i++)
	{
		int b;
		cin >> b;
		arrB.push_back(b);
	}

	int idxA=0,idxB=0;
	//정렬되어있는 배열이니까 출력만 하면된다.
	while (idxA < n && idxB < m)
	{
		if (arrA[idxA] > arrB[idxB])
			cout << arrB[idxB++] << ' ';
		else
			cout << arrA[idxA++] << ' ';
	}

	while (idxA < n)
	{
		cout << arrA[idxA++] << ' ';
	}
	while (idxB < m)
	{
		cout << arrB[idxB++] << ' ';
	}
}