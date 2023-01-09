#include<iostream>
#include<vector>
#include<algorithm>
//
using namespace std;
int n;
int a[1001];

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	//i+j+k = l ,  i,j,k각각 탐색 -> n3 1000 * 1000 * 1000 -> 시간초과
	//N^2(sum 배열) * log(N^2) = 2logN(이분탐색)  
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	vector<int> sumTwo;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			sumTwo.push_back(a[i] + a[j]);
		}
	}
	//sumTwo = i+j, sumTwo+k = l 를 만족시키는 l의 최대값 
	//sumTwo 배열 안에 l-k가 있는지 찾아봄
	sort(sumTwo.begin(), sumTwo.end());

	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (binary_search(sumTwo.begin(), sumTwo.end(), (a[i] - a[j])))
			{
				cout << a[i]; //l 값이 가장 클때 바로출력 
				return 0;
			}
		}
	}
}
