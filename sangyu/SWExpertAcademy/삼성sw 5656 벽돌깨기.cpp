#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int map[16][13];
int copymap[16][13];
int t;
int n, w, h;
vector<int> pos;
queue<pair<int, int>> q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ans = 100 * 100;

void boom(int arr[][13], int idx)
{
	//구슬위치에 따른 벽돌 제거를 실행합니다.
	//해당 열에 벽돌이 있는지 확인합니다.

	for (int j = 0; j < h; j++)
	{
		if (arr[j][idx] != 0)
		{
			q.push({ j,idx });
			break;
		}
	}

	while (!q.empty())
	{
		auto cur = q.front();
		int range = arr[cur.first][cur.second];

		q.pop();
		arr[cur.first][cur.second] = 0;

		//범위만큼 진행합니다.
		for (int j = 1; j < range; j++)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir] * j;
				int ny = cur.second + dy[dir] * j;

				//맵 밖으로 나가거나, 이미0이라면 연쇄로 폭발이 일어나지 않습니다.
				if (nx < 0 || ny < 0 || nx >= h || ny >= w)
					continue;
				if (arr[nx][ny] > 1)
					q.push({ nx,ny });
				else
					arr[nx][ny] = 0;

			}
		}



	}
	//벽돌을 내립니다.
	for (int k = 0; k < w; k++)
	{
		for (int i = h - 1; i >= 0; i--)
		{
			if (arr[i][k] == 0)
			{
				for (int y = i - 1; y >= 0; y--)
				{
					if (arr[y][k] != 0)
					{
						arr[i][k] = arr[y][k];
						arr[y][k] = 0;
						break;
					}
				}
			}
		}
	}

	//행렬을복사합니다.
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			copymap[i][j] = arr[i][j];
		}
	}
	return;

}

void backtrack(int cur, int arr[][13])
{
	//점수를 계산합니다.
	if (cur == n)
	{

		int cnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] > 0)
					cnt++;
			}
		}
		ans=min(ans, cnt);
		return;
	}

	int before[16][13];
	//중복을 허용한 경우의 수
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			for (int k = 0; k < w; k++)
			{
				before[j][k] = arr[j][k];
			}
		}

		boom(arr, i);
		backtrack(cur + 1, copymap);
		
		for (int j = 0; j < h; j++)
		{
			for (int k = 0; k < w; k++)
			{
				arr[j][k] = before[j][k];
			}
		}
	}
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> t;
	for(int i=1; i<=t; i++)
	{
		ans = 100 * 100;
		cin >> n >> w >> h;
		//입력
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		//n개의 구술에 대한 경우의 수 탐색
		backtrack(0, map);

		cout<<"#"<<i<<' '<< ans<<'\n';
	}
}


