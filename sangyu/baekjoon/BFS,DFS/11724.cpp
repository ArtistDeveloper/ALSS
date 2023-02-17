#include<iostream>
#include<vector>
using namespace std;

int n, m;
bool visited [10001];
vector<int> node[10001];
int cnt = 0;

void dfs(int nodeNum)
{
	visited[nodeNum] = true;
	for (int i = 0; i < node[nodeNum].size(); i++)
	{
		int idx = node[nodeNum][i]; //연결된 노드
		if (!visited[idx])
			dfs(idx);
	}
}
int main()
{
	//1방문 -> 1에 연결된거 방문 -> ... -> 방문마다 방문했음을 표시함.
	
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int s, d;
		cin >> s >> d;
		node[s].push_back(d);
		node[d].push_back(s);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << '\n';
}