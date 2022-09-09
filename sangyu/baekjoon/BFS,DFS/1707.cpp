#include<iostream>
#include<queue>
#include<memory.h>
#include<string>

using namespace std;

int visit[20001];

string bfs(int v_num, vector<vector<int>>& e_idx)
{
	queue<int> q;
	memset(visit, 0, (v_num + 1) * sizeof(int));
	//모든 노드가 연결되지 않음을 고려해야 함 ->  방문안한점에서 시작
	for (int j = 1; j <= v_num; j++)
	{
		//해당 노드를 방문했다면 넘어가야함 
		if (visit[j] != 0)
			continue;

		//아니면 bfs 
		q.push(j);
		visit[j] = 1;

		while (!q.empty())
		{

			int cur = q.front();
			//인접 노드들 탐색 
			for (int z = 0; z < e_idx[cur].size(); z++)
			{

				//방문했는지
				if (visit[e_idx[cur][z]] == 0)
				{
					//이분적이여야함 
					visit[e_idx[cur][z]] = -visit[cur];

					q.push(e_idx[cur][z]);
				}

				//같으면 이분적이지 않음
				if (visit[e_idx[cur][z]] == visit[cur])
					return "NO";
			}
			q.pop();

		}
	}

	return "YES";
}

int main()
{
	
	//인접 탐색 -> 색바꿈 으로 접근하면될거같은데

	//입력노드 많아짐 -> 서로 연결이 안된 그래프가 있을 수도 있음
	int test_case, v1,v2;
	cin >> test_case;
	vector<string> ans;

	for (int i = 0; i < test_case; i++)
	{
		//memset(visit, 0 , 2)
		int v_num, e_num;

		cin >> v_num >> e_num;
	
		vector<vector<int>> e_idx(v_num+1);

		for (int z = 0; z < e_num; z++)
		{

			cin >> v1 >> v2;
			//v1에 연결된 노드를 배열로 묶어놈 
			//v2에도 마찬가지로 표시해줘야함 
			e_idx[v1].push_back(v2);
			e_idx[v2].push_back(v1);
		}

		ans.push_back(bfs(v_num, e_idx));

	}

	for (auto i : ans)
		cout << i << endl;
}