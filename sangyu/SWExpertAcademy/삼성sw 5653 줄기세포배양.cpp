#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//300�ʰ� �ִ�, ��� �ٱ⼼���� 1�϶� �ִ� ����⸦ ������.
//150+150+50�� �ִ� ����Ⱑ�ɼ�����. 

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
		//���ð� ��ŭ �����մϴ�. 
		while (k--)
		{
			//�켱���� ť�� ����� ������� ū������ ���ĵǵ����մϴ�.
			//�ش� ������� -1 �̶�� �����մϴ�. ������� -x��� �װԵ˴ϴ�. 
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

					//0�κκ��� �ִٸ� �����մϴ�.
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
