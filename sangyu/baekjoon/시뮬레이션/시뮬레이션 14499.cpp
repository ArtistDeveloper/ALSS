#include<iostream>

using namespace std;

int n, m, x, y, k;
int map[21][21];
int dice[7]; //1 위, 2 북, 3 동, 4 서, 5 남, 6 아래

int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	//명령입력
	while (k--)
	{
		int command;
		cin >> command;

		if (x + dx[command] >= n || y + dy[command] >= m || x + dx[command] < 0 || y + dy[command] < 0)
		{
			continue;
		}
		//command에 따라 주사위를 회전시키고, 주사위를 이동시킵니다.
		int temp = dice[1];
		if (command == 1)
		{
			y += 1;
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = temp;
		}
		else if (command == 2)
		{
			y -= 1;
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = temp;
		}
	
		else if (command == 3)
		{
			x -= 1;
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = temp;
		}
		else if (command == 4)
		{
			x += 1;
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = temp;
		}
		     
		
		//윗면을 출력합니다.
		cout << dice[1]<<'\n';
		//도착한 보드칸이 0이면 복사합니다.
		if (map[x][y] == 0)
			map[x][y] = dice[6];
		//0이 아니면 밑면에 맵값을 복사하고 맵을 0으로 만듭니다.
		else
		{
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
	}
}