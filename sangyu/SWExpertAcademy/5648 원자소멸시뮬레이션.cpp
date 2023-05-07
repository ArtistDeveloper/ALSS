#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int tc, n, x, y, d, k;

struct info
{
	int x;
	int y;
	int dir;
	int energy;
	bool isLive=true;
};
vector<info> v;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };
int map[4001][4001];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> tc;

	for (int testcase = 0; testcase < tc; testcase++)
	{
		cin >> n;
		v.clear();
		//memset(map, 0, sizeof(map));


		for (int i = 0; i < n; i++)
		{
			cin >> x >> y >> d >> k;
			v.push_back({ (x + 1000)*2,(y + 1000)*2,d,k,true});
		}

		int ans = 0;
		
		while (true)
		{
			//모든원자가 없어졌다면 루프를 종료합니다.
			bool flag = true;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].isLive)
				{
					flag = false;
					break;
				}
			}

			if (flag)
				break;
			

			//원자들을 방향정보에따라 이동시킵니다.
			for (int i = 0; i < v.size(); i++)
			{
				if (!v[i].isLive)
					continue;

				int nx = v[i].x + dx[v[i].dir];
				int ny = v[i].y + dy[v[i].dir];
			
				//방향이 바뀌지 않음으로 범위초과시 충돌할일이 없음.
				if (nx < 0 || ny < 0 || nx >= 4001 || ny >= 4001)
				{
					v[i].isLive = false;
				}
				else if (v[i].isLive)
				{
					v[i].x = nx;
					v[i].y = ny;
					map[ny][nx]++;
				}
			}

			//충돌하는 원소여부를 확인합니다.
			for (int i=0; i<v.size(); i++)
			{
				//현재 위치의 원자개수가 2개이상이면. 충돌원자를 확인합니다.
				if (map[v[i].y][v[i].x] > 1)
				{
					for (int j=0; j<v.size(); j++)
					{
						if (v[j].isLive && v[i].x == v[j].x && v[i].y == v[j].y)
						{
							v[j].isLive = false;
							ans += v[j].energy;
						}
					}
				}
				map[v[i].y][v[i].x] = 0;
			}
			

		}

		cout << "#" << testcase+1 << ' ' << ans<<'\n';
	}
}


