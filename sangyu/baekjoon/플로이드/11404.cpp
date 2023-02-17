#include<iostream>
using namespace std;


int n, m; 
int table[101][101];
int INF = 100000*100;//�ִܰŸ��� �ּҰ��� �ִ뵵�� * �ƽ���-1 -> 
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			table[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int s, d, c;
		cin >> s >> d >> c;
		table[s][d] = min(table[s][d], c);
	}

	for (int i = 1; i <= n; i++)
	{
		table[i][i] = 0;
	}

	//V^2 * V -> O(V^3)
	//V 
	//1������ 5�������� ��带 ���ļ� ������ ���� �ִܰŸ��� ���̺� �����Ѵ�.
	for (int i = 1; i <= n; i++)
	{
		//V^2
		//���̺� �����ϱ� ���� 2�� for���� ����Ѵ�.
		for (int j = 1; j <= n; j++)
		{
			for (int z = 1; z <= n; z++)
			{
				//table[S][D] �� table[S][i] + table[i][D] ���� �۴ٸ� table[S][D]�� , �ƴϸ� table[S][i] + table[i][D]�� ����Ѵ�.
				
				table[j][z] =min(table[j][z], table[j][i] + table[i][z]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (table[i][j] == INF)
				cout << "0 ";
			else
				cout << table[i][j] <<' ';
		}
		cout << '\n';
	}
}