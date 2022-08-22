//#include<iostream>
//#include<queue>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
////2차원 배열 10만 x 10만 -> 너무큼.
//vector<int> vec[100001];
//int visit[100001] = {0,};
//int result[100001];
//
//int main()
//{
//	//v 정점 , e 간선, r 시작점
//	//1차원 bfs 어떻게 접근할지 
//	//인접 정점은 오름차순 순으로 방문.
//	int v,e, r;
//	
//	cin >> v >> e >> r;
//
//	for (int i = 0; i < e; i++)
//	{
//		int n1, n2;
//		cin >> n1 >> n2;
//		
//		//간선표시 
//		vec[n1].push_back(n2);
//		vec[n2].push_back(n1);
//	}
//
//	for (int i = 1; i <= v; i++)
//	{
//		sort(vec[i].begin(), vec[i].end());
//	}
//
//	/*for (int i = 0; i < v; i++)
//	{
//		for (int j = 0; j < vec[i].size(); j++)
//		{
//			cout << vec[i][j] << endl;
//		}
//	}*/
//
//	queue<int> q;
//	q.push(r);
//	visit[r] = 1;
//	int cnt = 0;
//	cnt++;
//	result[r] = cnt;
//
//	while (!q.empty())
//	{
//		int cur = q.front();
//		//cout << cur << endl;
//		
//		q.pop();
//
//		for (int i = 0; i < vec[cur].size(); i++)
//		{
//			//방문 안했으면 
//			if (!visit[vec[cur][i]])
//			{
//				cnt++;
//				result[vec[cur][i]] = cnt;
//				q.push(vec[cur][i]); // 큐에넣음 
//				visit[vec[cur][i]] = 1; //방문처리
//			}
//		}
//	}
//
//	for (int i = 1; i <= v; i++)
//	{
//		cout << result[i] << '\n';
//	}
//}

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

//2차원 배열 10만 x 10만 -> 너무큼.
vector<int> vec[100001];
int visit[100001] = {0,};
int result[100001];

int main()
{
	//v 정점 , e 간선, r 시작점
	//1차원 bfs 어떻게 접근할지 
	//인접 정점은 오름차순 순으로 방문.
	int v,e, r;
	
	cin >> v >> e >> r;

	for (int i = 0; i < e; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		
		//간선표시 
		vec[n1].push_back(n2);
		vec[n2].push_back(n1);
	}

	for (int i = 1; i <= v; i++)
	{
		sort(vec[i].begin(), vec[i].end());
	}

	/*for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << endl;
		}
	}*/

	queue<int> q;
	q.push(r);
	visit[r] = 1;
	int cnt = 0;
	cnt++;
	result[r] = cnt;

	while (!q.empty())
	{
		int cur = q.front();
		//cout << cur << endl;
		
		q.pop();

		for (int i = 0; i < vec[cur].size(); i++)
		{
			//방문 안했으면 
			if (!visit[vec[cur][i]])
			{
				cnt++;
				result[vec[cur][i]] = cnt;
				q.push(vec[cur][i]); // 큐에넣음 
				visit[vec[cur][i]] = 1; //방문처리
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		cout << result[i] << '\n';
	}
}
