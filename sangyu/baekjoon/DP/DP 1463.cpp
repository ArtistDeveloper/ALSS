#include<iostream>
#include<algorithm>
using namespace std;

int d[1000001];
int n;

int main()
{
	cin >> n;
	cin.tie(0); ios_base::sync_with_stdio(0);

	d[1] = 0;
	//1�� �������� ���� �ְ�, 2�� �������̳�, 3���� �������� �ּڰ��� �������Ͽ� ���ϸ�˴ϴ�.
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0)
			d[i] = std::min(d[i], d[i / 2] + 1);
		if (i % 3 == 0)
			d[i] = std::min(d[i] , d[i / 3] + 1);
	}
	
	cout << d[n];
}