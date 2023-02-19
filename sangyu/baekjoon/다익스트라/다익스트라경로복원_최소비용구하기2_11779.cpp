#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
const int INF = 100001 * 1000; 

vector<pair<int,int>> g[1005];
int dt[1005];
int pre[1005];
int start, dest;
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int s, d, c;
		cin >> s >> d >> c;
		g[s].push_back({c,d});
	}
	cin >> start >> dest;

	
	fill(dt, dt + n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dt[start] = 0; //�������� 

	pq.push({ dt[start],start });

	while (!pq.empty())
	{
		//second - ���, first - ���
		auto cur = pq.top();
		pq.pop();

		if (dt[cur.second] != cur.first) continue;

		for (auto nxt :g[cur.second])
		{
			//�ִܰŸ� ���̺��� ���� ũ�� continue;
			if (dt[nxt.second] <= nxt.first+dt[cur.second]) continue;

			//�ִܰŸ� ���̺��� �����Ҷ� ��� ������ ���� ���� ��带 �������.
			else
			{
				dt[nxt.second] = nxt.first + dt[cur.second];
				pq.push({dt[nxt.second], nxt.second});
				pre[nxt.second] = cur.second; 
			}
		}
	}

	cout << dt[dest] << '\n';

	vector<int> path;
	int cur = dest;
	while (cur != start)
	{
		path.push_back(cur);
		cur = pre[cur];
	}
	path.push_back(cur);

	cout << path.size()<<'\n';

	reverse(path.begin(), path.end());
	for (auto i : path)
	{
		cout << i << ' ';
	}
}