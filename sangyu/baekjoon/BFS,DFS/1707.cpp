#include<iostream>
#include<queue>
#include<memory.h>
#include<string>

using namespace std;

int visit[20001];

string bfs(int v_num, vector<vector<int>>& e_idx)
{
	queue<int> q;
	memset(visit, 0, (v_num + 1) * sizeof(int));
	//��� ��尡 ������� ������ ����ؾ� �� ->  �湮���������� ����
	for (int j = 1; j <= v_num; j++)
	{
		//�ش� ��带 �湮�ߴٸ� �Ѿ���� 
		if (visit[j] != 0)
			continue;

		//�ƴϸ� bfs 
		q.push(j);
		visit[j] = 1;

		while (!q.empty())
		{

			int cur = q.front();
			//���� ���� Ž�� 
			for (int z = 0; z < e_idx[cur].size(); z++)
			{

				//�湮�ߴ���
				if (visit[e_idx[cur][z]] == 0)
				{
					//�̺����̿����� 
					visit[e_idx[cur][z]] = -visit[cur];

					q.push(e_idx[cur][z]);
				}

				//������ �̺������� ����
				if (visit[e_idx[cur][z]] == visit[cur])
					return "NO";
			}
			q.pop();

		}
	}

	return "YES";
}

int main()
{
	
	//���� Ž�� -> ���ٲ� ���� �����ϸ�ɰŰ�����

	//�Է³�� ������ -> ���� ������ �ȵ� �׷����� ���� ���� ����
	int test_case, v1,v2;
	cin >> test_case;
	vector<string> ans;

	for (int i = 0; i < test_case; i++)
	{
		//memset(visit, 0 , 2)
		int v_num, e_num;

		cin >> v_num >> e_num;
	
		vector<vector<int>> e_idx(v_num+1);

		for (int z = 0; z < e_num; z++)
		{

			cin >> v1 >> v2;
			//v1�� ����� ��带 �迭�� ����� 
			//v2���� ���������� ǥ��������� 
			e_idx[v1].push_back(v2);
			e_idx[v2].push_back(v1);
		}

		ans.push_back(bfs(v_num, e_idx));

	}

	for (auto i : ans)
		cout << i << endl;
}