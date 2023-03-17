#include<iostream>
#include<vector>

using namespace std;
int n, m,minArea=100;
int map[9][9];
vector<pair<int, int>> cameraPos;

void Up(int temp[][9],int x, int y)
{
	for (int i = x - 1; i >= 0; i--)
	{

		if (temp[i][y] == 0)
		{
			temp[i][y] = -1;
		}
		else if (temp[i][y] == 6)
		{
			break;
		}
	}
}
void Down(int temp[][9],int x, int y)
{
	for (int i = x + 1; i < n; i++)
	{

		if (temp[i][y] == 0)
		{
			temp[i][y] = -1;
		}
		else if (temp[i][y] == 6)
		{
			break;
		}
	}
}
void Right(int temp[][9], int x, int y)
{
	for (int i = y + 1; i < m; i++)
	{

		if (temp[x][i] == 0)
		{
			temp[x][i] = -1;
		}
		else if (temp[x][i] == 6)
		{
			break;
		}
	}
}
void Left(int temp[][9], int x, int y)
{
	for (int i = y - 1; i >= 0; i--)
	{

		if (temp[x][i] == 0)
		{
			temp[x][i] = -1;
		}
		else if (temp[x][i] == 6)
		{
			break;
		}
	}
}

void tempMapRefresh(int tempMap[][9],int curMap[][9])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tempMap[i][j] = curMap[i][j];
		}
	}
}
//모든 경우에 대해 최적의 답을 찾아야합니다.
void BackTracking(int curMap[][9],int cur)
{
	//답을 저장하기 위한 맵을 선언해놓습니다.
	int tmpMap[9][9];
	tempMapRefresh(tmpMap,curMap);
	//카메라의 개수만큼 다 확인했다면 최소사각지대를 구합니다.
	if (cur == cameraPos.size())
	{
		int cnt=0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (curMap[i][j] == 0)
				{
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		if (cnt <= minArea)
			minArea = cnt;

		return;
	}

	
	//카메라의 위치와 개수에 따라 맵을 체크하고 다음 카메라에 위치를 체크합니다.
	//맵을 매번 갱신해줍니다.
	int curX = cameraPos[cur].first;
	int curY = cameraPos[cur].second;
	
	switch (map[curX][curY])
	{
	case 1:
	{
		Up(tmpMap,curX, curY);
		BackTracking(tmpMap,cur + 1);
		tempMapRefresh(tmpMap, curMap);

		Down(tmpMap, curX, curY);
		BackTracking(tmpMap,cur + 1);
		tempMapRefresh(tmpMap, curMap);

		Right(tmpMap, curX, curY);
		BackTracking(tmpMap, cur + 1);
		tempMapRefresh(tmpMap, curMap);

		Left(tmpMap, curX, curY);
		BackTracking(tmpMap, cur + 1);
		tempMapRefresh(tmpMap, curMap);
		break;
	}
	case 2:
	{
		Right(tmpMap, curX, curY);
		Left(tmpMap, curX, curY);
		BackTracking(tmpMap, cur + 1);
		tempMapRefresh(tmpMap, curMap);

		Up(tmpMap, curX, curY);
		Down(tmpMap, curX, curY);
		BackTracking(tmpMap, cur + 1);
		tempMapRefresh(tmpMap, curMap);

		break;
	}
	case 3:
	{
		Left(tmpMap, curX, curY);
		Up(tmpMap, curX, curY);
		BackTracking(tmpMap, cur + 1);
		tempMapRefresh(tmpMap, curMap);

		Right(tmpMap, curX, curY);
		Up(tmpMap, curX, curY);
		BackTracking(tmpMap, cur + 1);
		tempMapRefresh(tmpMap, curMap);

		Left(tmpMap, curX, curY);
		Down(tmpMap, curX, curY);
		BackTracking(tmpMap, cur + 1);
		tempMapRefresh(tmpMap, curMap);

		Right(tmpMap, curX, curY);
		Down(tmpMap, curX, curY);
		BackTracking(tmpMap, cur + 1);
		tempMapRefresh(tmpMap, curMap);
		break;
	}
	case 4:
	{
		Left(tmpMap, curX, curY);
		Right(tmpMap, curX, curY);
		Up(tmpMap, curX, curY);
		BackTracking(tmpMap, cur + 1);
		tempMapRefresh(tmpMap, curMap);

		Left(tmpMap, curX, curY);
		Right(tmpMap, curX, curY);
		Down(tmpMap, curX, curY);
		BackTracking(tmpMap, cur + 1);
		tempMapRefresh(tmpMap, curMap);

		Left(tmpMap, curX, curY);
		Up(tmpMap, curX, curY);
		Down(tmpMap, curX, curY);
		BackTracking(tmpMap, cur + 1);
		tempMapRefresh(tmpMap, curMap);

		Right(tmpMap, curX, curY);
		Up(tmpMap, curX, curY);
		Down(tmpMap, curX, curY);
		BackTracking(tmpMap, cur + 1);
		tempMapRefresh(tmpMap, curMap);
		break;
	}
	case 5:
	{
		Up(tmpMap, curX, curY);
		Down(tmpMap, curX, curY);
		Left(tmpMap, curX, curY);
		Right(tmpMap, curX, curY);
		BackTracking(tmpMap, cur + 1);
		tempMapRefresh(tmpMap, curMap);
	}
	}


}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6)
			{
				cameraPos.push_back({ i,j });
			}
		}
	}
	
	BackTracking(map,0);

	cout<<"minArea : " << minArea;
}


