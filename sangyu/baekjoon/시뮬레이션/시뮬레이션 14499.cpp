#include<iostream>

using namespace std;

int n, m, x, y, k;
int map[21][21];
int dice[7]; //1 ��, 2 ��, 3 ��, 4 ��, 5 ��, 6 �Ʒ�

int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	//����Է�
	while (k--)
	{
		int command;
		cin >> command;

		if (x + dx[command] >= n || y + dy[command] >= m || x + dx[command] < 0 || y + dy[command] < 0)
		{
			continue;
		}
		//command�� ���� �ֻ����� ȸ����Ű��, �ֻ����� �̵���ŵ�ϴ�.
		int temp = dice[1];
		if (command == 1)
		{
			y += 1;
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = temp;
		}
		else if (command == 2)
		{
			y -= 1;
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = temp;
		}
	
		else if (command == 3)
		{
			x -= 1;
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = temp;
		}
		else if (command == 4)
		{
			x += 1;
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = temp;
		}
		     
		
		//������ ����մϴ�.
		cout << dice[1]<<'\n';
		//������ ����ĭ�� 0�̸� �����մϴ�.
		if (map[x][y] == 0)
			map[x][y] = dice[6];
		//0�� �ƴϸ� �ظ鿡 �ʰ��� �����ϰ� ���� 0���� ����ϴ�.
		else
		{
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
	}
}