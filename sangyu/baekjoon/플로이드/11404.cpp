#include<iostream>
using namespace std;


int n, m; 
int table[101][101];
int INF = 100000*100;//최단거리의 최소값은 최대도시 * 맥스값-1 -> 
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
	//1번부터 5번까지의 노드를 거쳐서 갈때의 각각 최단거리를 테이블에 갱신한다.
	for (int i = 1; i <= n; i++)
	{
		//V^2
		//테이블에 접근하기 위해 2중 for문을 사용한다.
		for (int j = 1; j <= n; j++)
		{
			for (int z = 1; z <= n; z++)
			{
				//table[S][D] 가 table[S][i] + table[i][D] 보다 작다면 table[S][D]를 , 아니면 table[S][i] + table[i][D]를 사용한다.
				
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