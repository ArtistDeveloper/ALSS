#include<iostream>

using namespace std;

int n;
char star[400][400]; //4*100 -3 �϶� �ִ�

void recusion(int y, int x, int n)
{
	int len = 4 * n - 3;
	if (n == 1)
	{
		star[y][x] = '*';
		return;
	}
	else
	{
		//�� �Ʒ� ���̸�ŭ
		for (int i = x; i < x + len; i++)
		{
			star[y][i] = '*';
			star[y + len - 1][i] = '*';
		}

		//�翷 ���̸�ŭ
		for (int i = y; i < y + len; i++)
		{
			star[i][x] = '*';
			star[i][x + len - 1] = '*';
		}
	}
	//�������� 2ĭ
	recusion(y + 2, x + 2, n - 1);
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < 4*n-3; i++)
	{
		for (int j = 0; j < 4 * n - 3; j++)
		{
			star[i][j] = ' ';
		}
	}

	
	recusion(0, 0, n);

	for (int i = 0; i < 4 * n - 3; i++)
	{
		for (int j = 0; j < 4 * n - 3; j++)
		{
			cout << star[i][j];
		}
		cout << "\n";
	}
}