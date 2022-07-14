#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int board[502][502];
bool vist[502][502];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	//1로 연결됨 -> 그림
	//모든 그림 알아야함 , 그림의 크기 알아야함. 
	int x, y; //x -열 y 행
	cin >> x >> y;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> board[i][j];
		}
	}
	
	int num=0; //그림 개수 체크할겅
	int max = 0; //그림끼리 비교해서 max갑 너을거임
	queue<pair<int, int>> q; /
	int x_v[4] = { 1,0,-1,0 };
	int y_v[4] = { 0,1,0,-1 };

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (board[i][j] == 0 || vist[i][j]) //방문안해도 되는곳이거나  했으면
			{
				continue; //넘어간다
			}
			num++;
			int space = 0; //그림 공간 크기
			vist[i][j] = 1; //i,j부터 
			q.push({ i,j });
			
			while (!q.empty())
			{
				space++;
				pair<int, int> cur = q.front();
				q.pop();
				
				for (int v = 0; v < 4; v++) //방향 v
				{
					//방문을 했거나 그림이 아닌경우
					if (vist[cur.first + x_v[v]][cur.second + y_v[v]] == true || board[cur.first + x_v[v]][cur.second + y_v[v]] != 1)
						continue;
					//범위를 넘어간 경우 
					if (cur.first + x_v[v] < 0 || cur.first + x_v[v] >= x || cur.second + y_v[v] < 0 || cur.second + y_v[v] >= y)
						continue;

					//두겨우 제외하고 방문했다함.
					vist[cur.first + x_v[v]][cur.second + y_v[v]] = true;
					q.push({ cur.first + x_v[v] ,cur.second + y_v[v] });
				}
			}
			//최대크기 비교 
			max = std::max(max, space);
		
		}
	}
	cout << num << '\n' << max;
}