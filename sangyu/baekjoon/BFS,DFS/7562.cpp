#include<iostream>
#include<queue>
#include<vector>

using namespace std;


int main()
{
	int tc;
	cin >> tc;

	int ml;
	vector<int> ml_list;
	
	int x, y,x2,y2;
	vector<pair<int,int>> cur_location;
	vector<pair<int, int>> to_location;

	for (int i = 0; i < tc; i++)
	{
		cin >> ml;
		ml_list.push_back(ml);

		cin >> x >> y;
		cur_location.push_back({ x,y });

		cin >> x2 >> y2;
		to_location.push_back({ x2,y2 });
	}

	//나이트 움직임
	int dx[8] = { 2,2,1,1,-1,-1,-2,-2 };
	int dy[8] = { 1,-1,2,-2,2,-2,-1,1 };

	//tc만큼
	for (int i = 0; i < tc; i++)
	{
		int map[301][301] = { 0, };
		int visit[301][301] = { 0, };
		
		queue<pair<int, int>> q;

		//처음 위치
		q.push({ cur_location[i] });

		//방문체크
		visit[cur_location[i].first][cur_location[i].second] = 1;

		//bfs
		while (!q.empty())
		{
			pair<int, int> cur = q.front();
			q.pop();

			if (cur.first == to_location[i].first && cur.second == to_location[i].second)
			{
				cout << map[cur.first][cur.second] << '\n';
				break;
			}


			//이동
			for (int j = 0; j < 8; j++)
			{
				int nx = cur.first + dx[j];
				int ny = cur.second + dy[j];

				if (nx < 0 || nx >= ml_list[i] || ny < 0 || ny >= ml_list[i]) continue;
				if (visit[nx][ny]) continue;

				visit[nx][ny] = 1;
				q.push({ nx,ny });
				map[nx][ny] = map[cur.first][cur.second] + 1;
			}
		}
	}
}