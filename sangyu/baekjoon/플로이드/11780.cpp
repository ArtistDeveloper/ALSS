#include<iostream>
#include<vector>
using namespace std;

int n, m;
const int INF=100000*110+1; //각각비용이 100,000이고, 100개의 점을 모두 지나야한다면 최대비용..

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


	//최단거리 테이블 및 경로복원을 위한 테이블 작성
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (table[i][j] > table[i][k] + table[k][j])
				{
					table[i][j] = table[i][k] + table[k][j];
					//s->t보다 s->k, k->t가는게 더 효율적 
					//nxt[s][t]-> nxt[s][1]로 갔다가 [1][s]로 감.
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

	//줄 i->j로 가는 최소비용에 포함되어 있는 도시 개수 -> size 
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