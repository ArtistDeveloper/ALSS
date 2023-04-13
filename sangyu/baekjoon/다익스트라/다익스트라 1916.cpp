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

	//�켱����ť�� 0, �������� �߰��մϴ�.
	dt[start] = 0;
	pq.push({ dt[start],start });
	

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		//ť�� �Ÿ��ִ� �Ÿ��� �ִܰŸ� ���̺�� �ٸ���� continue�մϴ�.
		if (dt[cur.second] != cur.first)
			continue;

		//�̿������鿡 ���� ���̺��� �����մϴ�.
		for (auto nxt : g[cur.second])
		{
			//�ִܰŸ� ���̺��� ���� ũ�� continue;
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
