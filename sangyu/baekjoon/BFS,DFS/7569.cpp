#include<iostream>
#include<queue>
#include<memory.h>

using namespace std;

int box[101][101][101];
int visit[101][101][101];

struct three_int
{
	int x;
	int y;
	int z;

	three_int(int z, int y, int x) : x(x), y(y), z(z)
	{

	}

};
int main()
{
	
	//cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);


	memset(visit, -1, sizeof(box));



	int dx[6] = { 1,0,-1,0,0,0 };
	int dy[6] = { 0,0,0,-1,0,1 };
	int dz[6] = { 0,1,0,0,-1,0 };

	queue<three_int> q;

	// m - 가로 , n - 세로 , h - 상자의 수  
	// 1 익은 토마토, 0 익지 않은 토미토 , -1 토마토 들어있지 않은 칸
	//최소일수 구해야함.
	int m, n, h;
	cin >> m >> n >> h;
	three_int start = {  -1,-1,-1 };
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int z = 0; z < m; z++)
			{
				cin >> box[i][j][z];
				if (box[i][j][z] == -1)
				{
					visit[i][j][z] = -2; // -2 은 탐색 x , 일수이 포함하지 않을것임.
				}
				if (box[i][j][z] == 1)
				{
					
					start = { i,j,z };//시작지점 정해줌
					q.push(start);
					visit[i][j][z] = 0;
				}
			}
		}
	}

	while (!q.empty())
	{
		start = q.front();
		q.pop();

		//x,y,z 방향으로 탐색할것임. 
	
		for (int dir = 0; dir < 6; dir++)
		{
			//탐색 범위를 벗어난 경우
			if (start.z + dz[dir] >= h || start.y + dy[dir] >= n || start.x + dx[dir] >= m || start.z + dz[dir] < 0 || start.y + dy[dir] < 0 || start.x + dx[dir] < 0)
				continue;
			////이미 토마토가 익었거나, 채워지지 않는 경우
			//if (box[start.z + dz[dir]][start.y + dy[dir]][start.x + dx[dir]] == 1 || box[start.z + dz[dir]][start.y + dy[dir]][start.x + dx[dir]] == -1)
			//	continue;
			// 
			//방문하지 않은경우
			if (visit[start.z + dz[dir]][start.y + dy[dir]][start.x + dx[dir]] == -1 && box[start.z + dz[dir]][start.y + dy[dir]][start.x + dx[dir]] == 0)
			{
				q.push({ start.z + dz[dir],start.y + dy[dir],start.x + dx[dir] });
				visit[start.z + dz[dir]][start.y + dy[dir]][start.x + dx[dir]] = visit[start.z][start.y][start.x] + 1;
			}
		}
			
		
	}

//토마토가 익지않은상태..
	int ans = 0;
	for(int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int z = 0; z < m; z++)
			{
				if (box[i][j][z] == -1)
					continue;
				if (visit[i][j][z] == -1)
				{
					cout << "-1" << "\n";
					return 0;
				}
				ans=max(ans, visit[i][j][z]);
			}
		}
	}

	cout << ans << "\n";

}