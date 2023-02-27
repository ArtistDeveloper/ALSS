#include <iostream>
#include <queue>

using namespace std;

int visited[100002];
int n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue<int> q;
	fill(visited, visited + 100001, -1);

	cin >> n >> k;
	
	// 1. BFS 시작점 삽입 및 방문체크
	visited[n] = 0;
	q.push(n);
	
	// 2. BFS수행
	while (visited[k] == -1) // q.empty()를 조건으로 설정하게되면 0,0이 반례가 된다.
	{
		int curPos = q.front(); q.pop();

		for (int nx : {curPos - 1, curPos + 1, 2 * curPos})
		{
			// if (nx < 0 || nx >= 100000) continue; // 조건 설정을 >=로 하면 메모리초과 발생
			if (nx < 0 || nx > 100000) continue;
			if (visited[nx] != -1) continue;
			visited[nx] = visited[curPos] + 1;
			q.push(nx);
		}
	}

	cout << visited[k];

	return 0;
}
