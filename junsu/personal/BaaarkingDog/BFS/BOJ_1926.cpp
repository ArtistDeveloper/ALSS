#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define Y first // 행
#define X second // 열

int board[502][502];
int visited[502][502];

int ROW_SIZE = 0;
int COL_SIZE = 0;

int dy[4] = { -1, +1, 0, 0 };
int dx[4] = { 0, 0, -1, +1 };

// 그림의 개수, 그림의 넓이 저장 변수
int picCount = 0;
int maxWidthCount = 0;


queue<pair<int, int>> q;

void bfs()
{
	picCount += 1;
	int localWidthCount = 0;

	while (!q.empty())
	{
		pair<int, int> nowPos = q.front();
		q.pop();
		localWidthCount++;

		for (int i = 0; i < 4; i++)
		{
			int nowY = nowPos.Y + dy[i];
			int nowX = nowPos.X + dx[i];
			if (nowX < 0 || nowX >= COL_SIZE || nowY < 0 || nowY >= ROW_SIZE) continue;
			if (visited[nowY][nowX] || board[nowY][nowX] != 1) continue;

			visited[nowY][nowX] = 1;
			q.push({ nowY, nowX });
		}
	}

	if (maxWidthCount < localWidthCount) maxWidthCount = localWidthCount;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// 1. 값 입력
	cin >> ROW_SIZE >> COL_SIZE;
	
	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COL_SIZE; j++)
		{
			cin >> board[i][j];
		}
	}
	

	// 2. 모든 지역에 대해 BFS수행
	for (int i = 0; i < ROW_SIZE; i++)
	{
		for (int j = 0; j < COL_SIZE; j++)
		{
			if ((visited[i][j] == 0) && (board[i][j] == 1))
			{
				q.push({ i, j });
				visited[i][j] = 1;
				bfs();
			}
		}
	}
	
	cout << picCount << '\n' << maxWidthCount;

	return 0;
}

