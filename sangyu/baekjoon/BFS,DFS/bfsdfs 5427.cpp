#include<iostream>
#include<queue>
using namespace std;

int n;
char map[1001][1001];
int distFire[1001][1001];
int distPerson[1001][1001];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

//불에 대해 bfs를 통해 거리를 계산하고, 사람에 대한 bfs를 수행합니다. 이때 불의 전파시간을 고려합니다.
void bfs(int x, int y)
{
	queue<pair<int, int>> qFire;
	queue<pair<int, int>> qPerson;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
		
			cin >> map[i][j];
			if (map[i][j] == '@')
			{
				qPerson.push({ i,j });
				distPerson[i][j] = 1;
			}
			if (map[i][j] == '*')
			{
				qFire.push({ i,j });
				distFire[i][j] = 1;
			}
		}
	}


	//불에 대해 bfs를 수행합니다.
	while (!qFire.empty())
	{
		pair<int, int> cur = qFire.front();
		qFire.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || ny < 0  || x <= nx || y <= ny)
				continue;
			if (distFire[nx][ny] !=0 || map[nx][ny] == '#')
				continue;
			      
			distFire[nx][ny] = distFire[cur.first][cur.second] + 1;
			qFire.push({ nx,ny });
		}
	}

	//나가면 위치를 출력하고 반환합니다.
	while (!qPerson.empty())
	{
		pair<int, int> cur = qPerson.front();
		qPerson.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];


			//범위밖에 나간다면 탈출하는것입니다.
			if (nx < 0 || ny < 0 || x <= nx || y <= ny)
			{
				cout << distPerson[cur.first][cur.second] << '\n';
				return;
			}


			if (map[nx][ny] == '#' || distPerson[nx][ny] || map[nx][ny]=='*')
				continue;

			//불이 더 빠르게 다음지점에 도착했다면 continue해야합니다.
			if (distFire[nx][ny] != 0 && distFire[nx][ny] <= distPerson[cur.first][cur.second] + 1)
				continue;


			distPerson[nx][ny] = distPerson[cur.first][cur.second] + 1;
			qPerson.push({ nx,ny });
		}	
	}
	cout << "IMPOSSIBLE" << '\n';
	return;
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;

	while (n--)
	{
		int x, y;
		cin >> y >> x;

		//Init
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				distFire[i][j] = 0;
				distPerson[i][j] = 0;
			}
		}

		bfs(x, y);

	}

}