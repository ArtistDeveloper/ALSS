#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int n, m;
const int maxNum = 100001 * 1000;

vector<pair<int, int>> g[1005];
int dt[1005];
int start, dest;

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int s, d, c;
		cin >> s >> d >> c;
		g[s].push_back({ c,d });
	}

	cin >> start >> dest;

	fill(dt, dt + n + 1, maxNum);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	//우선순위큐에 0, 시작점을 추가합니다.
	dt[start] = 0;
	pq.push({ dt[start],start });
	

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		//큐의 거리있는 거리가 최단거리 테이블과 다를경우 continue합니다.
		if (dt[cur.second] != cur.first)
			continue;

		//이웃정점들에 대해 테이블을 갱신합니다.
		for (auto nxt : g[cur.second])
		{
			//최단거리 테이블보다 값이 크면 continue;
			if (dt[nxt.second] <= nxt.first + dt[cur.second]) continue;

			else
			{
				dt[nxt.second] = nxt.first + dt[cur.second];
				pq.push({ dt[nxt.second], nxt.second });
			}
		}
	}

	cout << dt[dest] << '\n';

}
