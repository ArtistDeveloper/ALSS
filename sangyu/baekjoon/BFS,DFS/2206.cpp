#include<iostream>
#include<queue>
#include<string>
using namespace std;

char board[1001][1001];

//dist[][][0] ->dist[][][1]로 할시 된다면 벽을 부셔도될듯?? 개천재 
int dist[1001][1001][2];

int main()
{
	int a, b;

	cin >> a >> b;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cin >> board[i][j];
		}
	}

	
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	queue<pair<int,pair<int,int>>> q;

	//시작위치
	q.push({ 1,{0,0}});
	dist[0][0][1] = 1;


	//breakable
	int breakable;
	while (!q.empty())
	{
		int cur_idx_x = q.front().second.first;
		int cur_idx_y = q.front().second.second;
		int break_board = q.front().first;

		q.pop();
		

		for (int i = 0; i < 4; i++)
		{
			
			int nx_idx_x = cur_idx_x + dx[i];
			int nx_idx_y = cur_idx_y + dy[i];


			//범위를 넘어가면 continue 
			if (nx_idx_x >= a || nx_idx_y >= b || nx_idx_x < 0 || nx_idx_y < 0)
				continue;


			//방문가능한 곳이라면 (벽 && 부수기 가능)
			if (board[nx_idx_x][nx_idx_y] == '1' && break_board)
			{
				dist[nx_idx_x][nx_idx_y][break_board - 1] = dist[cur_idx_x][cur_idx_y][break_board]+1;
				q.push({ break_board - 1, { nx_idx_x,nx_idx_y }});
			}
			//방문한 곳이라면  (이동가능 && 방문 x)
			if ((board[nx_idx_x][nx_idx_y]=='0' && !dist[nx_idx_x][nx_idx_y][break_board]))
			{
				dist[nx_idx_x][nx_idx_y][break_board] = dist[cur_idx_x][cur_idx_y][break_board] + 1;
				q.push({ break_board, { nx_idx_x,nx_idx_y } });

			}
			
		}
		breakable = break_board;
	}
	if (dist[a - 1][b - 1][breakable] == 0)
		cout << "-1" << endl;
	else
		cout << dist[a - 1][b - 1][breakable] << '\n';
	

}