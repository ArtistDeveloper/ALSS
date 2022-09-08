#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int board[101]={0};
int visit[101]={0};


int main()
{
	const int start = 1;
	const int goal = 100;

	//1차원 bfs로 해결을 해봐야할둣
	for (int i = 1; i < 101; i++)
	{
		board[i] = i;
		visit[i] = -1;
	}


	int ladder_num, snake_num;

	cin >> ladder_num >> snake_num;

	int x, y;
	//맵에 사다리 표시
	for (int i = 0; i < ladder_num; i++)
	{
		cin >> x >> y;
		board[x] =y;
	}

	for (int i = 0; i < snake_num; i++)
	{
		cin >> x >> y;
		board[x] = y;

	}

	//이동이 1~6이니까 따로 안만들어줘도 될듯함

	queue<int> q;
	q.push(start);
	
	//1부터 시작하니까
	visit[start] = 0;


	while (!q.empty())
	{

		int cur_idx = q.front();
		q.pop();


		for (int i = 1; i <= 6; i++)
		{
			int nx_idx = cur_idx + i;

			if (nx_idx > goal)
				break;
			
			nx_idx = board[nx_idx];

			if (visit[nx_idx] == -1)
			{
				visit[nx_idx] = visit[cur_idx] + 1;
				q.push(nx_idx);
			}
		}
	}
	cout << visit[goal] << endl;
}