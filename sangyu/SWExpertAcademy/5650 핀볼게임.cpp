#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int tc, n;
int map[101][101];

//�Ʒ�,����,��,��
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int rotDirbyBlock[5][4] = {

	{1,3,0,2},
	{2,3,1,0},
	{2,0,3,1},
	{3,2,0,1},
	{2,3,0,1},

};
int rotDirbyWall[4] = { 2,3,0,1 };
int main()
{
	cin >> tc;

	for (int testCase = 0; testCase < tc; testCase++)
	{
		cin >> n;
		vector<pair<int, int>> ballPos;

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				//�ɺ��� ������ġ�� ���մϴ�.
				if (map[i][j] == 0)
					ballPos.push_back({ i,j });
			}
		}

		//��ġ�� ����ŭ ��ȸ�� ���� �ִ밪�� ���մϴ�.
		for (auto cur : ballPos)
		{
			//4���� ���⿡ ���� �����մϴ�.(�Ʒ�, ������, ��, ����)
			for (int k = 0; k < 4; k++)
			{
				int score = 0;
				int dir = k;
				//���̳�, ����� ���������� ��� �����մϴ�.
				int nx = cur.first;
				int ny = cur.second;
				while (true)
				{
					nx += dx[dir];
					ny += dy[dir];

					//�ٽ� ����������� ���ƿ´ٸ� �����Ե˴ϴ�.

					if (nx == cur.first && ny == cur.second)
					{
						ans = max(ans, score);
						break;
					}
					//��Ȧ�� ������ �����Ե˴ϴ�.
					else if (map[nx][ny] == -1)
					{

						ans = max(ans, score);
						break;
					}
					//���� ��� ������ ȸ����ŵ�ϴ�.
					else if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					{
						score++;
						dir = rotDirbyWall[dir];
					}
					//����� ��� ������ ȸ����ŵ�ϴ�.
					else if (map[nx][ny] >= 1 && map[nx][ny] <= 5)
					{
						score++;
						dir = rotDirbyBlock[map[nx][ny] - 1][dir];
					}

					//��Ȧ�� ��� �ٸ� ��Ȧ�� ã��, ��ġ�� ��ȯ�մϴ�.
					else if (map[nx][ny] >= 6 && map[nx][ny] <= 10)
					{
						for (int col = 0; col < n; col++)
						{
							bool flag = false;
							for (int row = 0; row < n; row++)
							{
								//���� ��Ȧ������ ��ġ�� �ٸ���
								if (map[nx][ny] == map[col][row] && (nx != col && ny != row))
								{
									flag = true;

									nx = col;
									ny = row;
									break;
								}
							}
							if (flag)
								break;
						}
					}
				}
			}
		}
		cout << "#" << testCase + 1 << ' ' << ans << endl;

	}

}
