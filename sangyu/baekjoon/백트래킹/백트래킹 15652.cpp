#include<iostream>
using namespace std;
int n,m;
int arr[10];

void func(int cur)
{
	if (cur == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i]<<' ';
		}
		cout << '\n';
		return;
	}

	//���� ���� �Ἥ ������ �����ϰ�, �ߺ��� ������ ������ ��������, �ڱ⺸�� ���� ���� ������ �̷�� ���� �������.
	for (int i = 1; i <= n; i++)
	{
		if (cur == 0)
		{
			arr[cur] = i;
			func(cur + 1);
		}
		else if (cur>=1)
		{
			if (i >= arr[cur - 1])
			{
				arr[cur] = i;
				func(cur + 1);
			}
		}
	}
	
}
int main()
{
	cin >> n >> m;
	func(0);

}