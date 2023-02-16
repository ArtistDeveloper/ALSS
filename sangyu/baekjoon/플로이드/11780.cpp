#include<iostream>
#include<vector>
using namespace std;

int n, m;
const int INF=100000*110+1; //��������� 100,000�̰�, 100���� ���� ��� �������Ѵٸ� �ִ���..

int table[105][105];
int nxt[105][105];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
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
		int a, b, cost;
		cin >> a >> b >> cost;
		if (table[a][b] > cost)
		{
			table[a][b] = min(table[a][b], cost);
			nxt[a][b] = b;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		table[i][i] = 0;
	}


	//�ִܰŸ� ���̺� �� ��κ����� ���� ���̺� �ۼ�
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (table[i][j] > table[i][k] + table[k][j])
				{
					table[i][j] = table[i][k] + table[k][j];
					//s->t���� s->k, k->t���°� �� ȿ���� 
					//nxt[s][t]-> nxt[s][1]�� ���ٰ� [1][s]�� ��.
					nxt[i][j] = nxt[i][k];
				}
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
			cout << table[i][j] << ' ';
		}
		cout << '\n';
	}

	//�� i->j�� ���� �ּҺ�뿡 ���ԵǾ� �ִ� ���� ���� -> size 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (table[i][j] == 0 || table[i][j] == INF)
			{
				cout << "0\n";
					continue;
			}
			vector<int> path;
			int st = i;
			while (st != j)
			{
				path.push_back(st);
				st = nxt[st][j];
			}
			path.push_back(j);
			cout << path.size() << ' ';

			for (auto x : path)
				cout << x << ' ';
			
			cout << '\n';
		}

	}
}