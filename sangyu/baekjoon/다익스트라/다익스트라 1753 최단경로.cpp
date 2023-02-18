#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int v, e, k;


const int INF = 3000005; //10* 300000 일때가 최대
vector<pair<int,int>> adj[20005]; //비용 간선
int distanceTable[20005];
priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; 

int main()
{

	//우선순위 큐를 이용한 다익스트라는 특정 정점의 거리가 확정되었는지 여부를 따로 저장하진 않음.
	//우선순위 큐에 가장 거리가 작은 원소 선택(0,시작점).

	//최단거리 테이블에서 d[시작점]이 =0이 맞는지 확인.
	//시작점에서 갈수 있는 정점들 확인 후 작다면 갱신 
	//힙에 (거리,정점) 쌍을 추가
	//우선순위 큐에 가장 거리가 작은 원소 선택 후 최단거리 테이블과 맞는지 확인.
	//거리가 가장 작은 원소에서 갈수 있는 정점을 확인하고 최단거리 테이블에 저장된 값보다 작다면 갱신하고 큐에 삽입.
	//우선순위 큐가 빌때까지 반복
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> v >> e >> k;
	fill(distanceTable, distanceTable + v+1, INF);



	for (int i = 0; i < e; i++)
	{
		int u, node, w;
		cin >> u >> node >> w;
		adj[u].push_back(make_pair(w, node)); //u->v로 갈때 가중치 w
	}


	distanceTable[k] = 0; //시작 지점의 거리는 0으로.
	pq.push(make_pair(distanceTable[k], k)); //우선순위 큐에 시작 정점 넣기.

	//시작정점으로부터 이동할 수 있는 정점정보
	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		
		//최단거리 테이블의 값과 우선순위 큐의 값이 다르면 건너뛴다.
		//특정 정점에 대한 거리를 확정시킨 여부가 없기 때문에. 같은 정점에 대해 현재 거리값이 최단거리 값인지 검사를 함.
		if (distanceTable[cur.second] != cur.first)
			continue;

		for (auto nxt : adj[cur.second])
		{
			//정점의 거리가 최단 거리 테이블보다 작다면 갱신 후 큐에 추가.
			if (distanceTable[nxt.second] <= distanceTable[cur.second] + nxt.first)
				continue;
			
			distanceTable[nxt.second] = distanceTable[cur.second] + nxt.first;
			pq.push(make_pair(distanceTable[nxt.second], nxt.second));
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (distanceTable[i] == INF) cout << "INF\n";
		else cout << distanceTable[i] << "\n";
	}
}