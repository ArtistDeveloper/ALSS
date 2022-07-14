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
	//1�� ����� -> �׸�
	//��� �׸� �˾ƾ��� , �׸��� ũ�� �˾ƾ���. 
	int x, y; //x -�� y ��
	cin >> x >> y;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> board[i][j];
		}
	}
	
	int num=0; //�׸� ���� üũ�Ұ�
	int max = 0; //�׸����� ���ؼ� max�� ��������
	queue<pair<int, int>> q; /
	int x_v[4] = { 1,0,-1,0 };
	int y_v[4] = { 0,1,0,-1 };

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (board[i][j] == 0 || vist[i][j]) //�湮���ص� �Ǵ°��̰ų�  ������
			{
				continue; //�Ѿ��
			}
			num++;
			int space = 0; //�׸� ���� ũ��
			vist[i][j] = 1; //i,j���� 
			q.push({ i,j });
			
			while (!q.empty())
			{
				space++;
				pair<int, int> cur = q.front();
				q.pop();
				
				for (int v = 0; v < 4; v++) //���� v
				{
					//�湮�� �߰ų� �׸��� �ƴѰ��
					if (vist[cur.first + x_v[v]][cur.second + y_v[v]] == true || board[cur.first + x_v[v]][cur.second + y_v[v]] != 1)
						continue;
					//������ �Ѿ ��� 
					if (cur.first + x_v[v] < 0 || cur.first + x_v[v] >= x || cur.second + y_v[v] < 0 || cur.second + y_v[v] >= y)
						continue;

					//�ΰܿ� �����ϰ� �湮�ߴ���.
					vist[cur.first + x_v[v]][cur.second + y_v[v]] = true;
					q.push({ cur.first + x_v[v] ,cur.second + y_v[v] });
				}
			}
			//�ִ�ũ�� �� 
			max = std::max(max, space);
		
		}
	}
	cout << num << '\n' << max;
}