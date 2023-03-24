#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int ans;
int score[4] = { 1,2,4,8 };
vector<int> gear[4];
int k;

int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int n;
			scanf_s("%1d", &n);
			gear[i].push_back(n);
		}
	}


	cin >> k;
	while (k--)
	{
		int num, dir;
		cin >> num >> dir;

		//���� ������ ȸ������ �ʰ�, ���� �ٸ��ٸ� �ݴ�������� ȸ���մϴ�.
		int idx = num - 1;

		int dirs[4] = {};
		dirs[idx] = dir;

		//-> ���� ȸ���� �����մϴ�.
		for (int i = idx; i < 3; i++)
		{
			if (gear[i][2] != gear[i + 1][6])
			{
				cout << "-> ���� :" << i<<endl;
				dirs[i + 1] = -dirs[i];
			}
			
		}

		//<- ���� ȸ���� �����մϴ�.	
		for (int i = idx; i > 0; i--)
		{
			if (gear[i][6] != gear[i - 1][2])
			{
				cout << "<- ���� : " << i << endl;
				dirs[i - 1] = -dirs[i];
			}
		}
		
		//ȸ���մϴ�.
		for (int i = 0; i < 4; i++)
		{
			if (dirs[i] == -1)
				rotate(gear[i].begin(), gear[i].begin() + 1, gear[i].end());
			else if (dirs[i] == 1)
				rotate(gear[i].begin(), gear[i].begin() + 7, gear[i].end());
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (gear[i][0] ==1)
		{
			ans += score[i];
		}
	}
	cout << ans;
}