#include<iostream>
#include<queue>

using namespace std;

#define x first
#define y second 

int box[1001][1001];
int dist[1001][1001];

int main()
{
	int n, m;

	cin >> n >> m;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
			{
				q.push({ i,j });

			}
			if (box[i][j] == 0)
			{
				box[i][j] == -1;
			}
		}
	}
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int day = 0;
	//큐 생성 
	//방문처리
	while (!q.empty())
	{
		
		pair<int, int> cur = q.front();
		cout << q.front().x << q.front().y <<endl ;
		q.pop();
		//상하좌우 탐색
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			//-1 은 토마토가 들어있지 않은 칸임.
			if (dist[nx][ny]>0 || box[nx][ny] == -1)
				continue;
			//범위를 넘어선 값 도 continue
			if (nx<0 || nx >= n || ny < 0 || ny>=m)
				continue;
			//예외처리하고 남은것들은 push 및 visit 
			dist[nx][ny] = dist[cur.x][cur.y]++;
			q.push({ nx,ny });
			
		}
		
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (day < dist[i][j])
				day = dist[i][j];
		}
	}
	cout << day;
}