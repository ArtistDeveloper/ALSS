#include<iostream>

using namespace std;

int n,m;
int ans[10];
void func(int cur)
{
	//������ ������ m�� ��� ����� �մϴ�.
	if (cur == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << "\n";
		return;
	}


	//m���� �ƴ϶�� �������� �ø��Ե˴ϴ�.
	//���� �ߺ������� �ߺ�üũ�� ���� �ʽ��ϴ�.
	for (int i = 1; i <= n; i++)
	{
		ans[cur] = i;
		func(cur + 1);
	}
}

int main()
{
	cin >> n >> m;
	func(0);
}