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
		int idx = node[nodeNum][i]; //����� ���
		if (!visited[idx])
			dfs(idx);
	}
}
int main()
{
	//1�湮 -> 1�� ����Ȱ� �湮 -> ... -> �湮���� �湮������ ǥ����.
	
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