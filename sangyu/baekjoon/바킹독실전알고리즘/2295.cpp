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

	//i+j+k = l ,  i,j,k���� Ž�� -> n3 1000 * 1000 * 1000 -> �ð��ʰ�
	//N^2(sum �迭) * log(N^2) = 2logN(�̺�Ž��)  
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
	//sumTwo = i+j, sumTwo+k = l �� ������Ű�� l�� �ִ밪 
	//sumTwo �迭 �ȿ� l-k�� �ִ��� ã�ƺ�
	sort(sumTwo.begin(), sumTwo.end());

	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (binary_search(sumTwo.begin(), sumTwo.end(), (a[i] - a[j])))
			{
				cout << a[i]; //l ���� ���� Ŭ�� �ٷ���� 
				return 0;
			}
		}
	}
}
