#include<iostream>
#include<vector>
#include<deque>
#include<queue>
using namespace std;

int boardSize, appleNum, rotateNum;
int board[105][105];

//아래, 오른쪽, 위, 왼쪽
int dx[4] = { 1, 0, -1, 0 };  
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, char>> switchDir;

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> boardSize >> appleNum;

	for (int i = 0; i < appleNum; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y]=1;
	}

	cin >> rotateNum;
	while (rotateNum--) {
		// 방향전환
		int c;
		char d;
		cin >> c >> d;
		switchDir.push({ c, d });
	}

	//시작지점을 표시해줍니다.
	deque<pair<int, int>> q;
	q.push_front({ 1,1 });

	int dir = 1;
	int time = 0;
	int timeIdx = 0;
	while (true)
	{
		dir %= 4;
		auto cur= q.front();

		//방문처리를합니다.
		board[cur.first][cur.second] = 2;
		time++;

		int nx = cur.first + dx[dir];
		int ny = cur.second + dy[dir];


		//벽에 닿거나, 자기 자신에게 닿으면 멈춥니다.
		if (nx < 1 || ny < 1 || ny > boardSize || nx > boardSize)
			break;
		if (board[nx][ny] == 2)
			break;

		//이동한 칸에 사과가 없다면 몸길이를 줄여서 꼬리가 위치한 칸을 바꿉니다.
		if (board[nx][ny] ==0)
		{
			board[q.back().first][q.back().second] = 0;
			q.pop_back();
		}

		//시간이 증가함에 따라 방향을 전환합니다.
		if (!switchDir.empty())
		{
			auto sd = switchDir.front();
			if (sd.first == time) {
				if (sd.second == 'L') dir += 1;
				else if (sd.second == 'D') dir += 3;
				switchDir.pop();
			}
		}

		q.push_front({ nx,ny });

	}

	cout << time;
}