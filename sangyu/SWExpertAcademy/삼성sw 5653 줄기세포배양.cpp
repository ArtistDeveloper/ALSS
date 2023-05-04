#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//300초가 최대, 모든 줄기세포가 1일때 최대 배양용기를 차지함.
//150+150+50이 최대 배양용기가될수있음. 

int map[351][351];
int copymap[351][351];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return map[a.first][a.second] < map[b.first][b.second];
	}
};




int main()
{
	int t;
	cin >> t;

	for (int tc = 0; tc < t; tc++)
	{
		int n, m, k;
		cin >> n >> m >> k;

		memset(map, 0, sizeof(map));
		vector<pair<int, int>> v;
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[150+i][150+j];
				if (map[150 + i][150 + j] > 0)
					v.push_back({ 150 + i,150 + j });
			}
		}

		memcpy(copymap, map, sizeof(map));
		cout << endl;
		for (int i = 150; i < n; i++)
		{
			for (int j = 150; j < m; j++)
			{
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}
		int dead=0;
		int total = v.size();
		//배양시간 만큼 수행합니다. 
		while (k--)
		{
			//우선순위 큐를 사용해 생명력이 큰순으로 정렬되도록합니다.
			//해당 생명력이 -1 이라면 번식합니다. 생명력이 -x라면 죽게됩니다. 
			for (auto pos : v)
			{

				copymap[pos.first][pos.second]--;

				if (copymap[pos.first][pos.second] == -1)
				{
					pq.push({ pos.first,pos.second });
				}
				if (copymap[pos.first][pos.second] == -map[pos.first][pos.second])
				{
					dead++;
				}
			}

			while (!pq.empty())
			{
				auto cur = pq.top();
				pq.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					//0인부분이 있다면 번식합니다.
					if (map[nx][ny] == 0)
					{
						v.push_back({ nx,ny });
						map[nx][ny] = map[cur.first][cur.second];
						copymap[nx][ny] = map[cur.first][cur.second];
						total++;
					}
				}
			}
		}
		cout << "#" << tc << ' ' << total <<' '<<dead << '\n';

		cout << "#" << tc << ' ' << total - dead << '\n';
	}
}
