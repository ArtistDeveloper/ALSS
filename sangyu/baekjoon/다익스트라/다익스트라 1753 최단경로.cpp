#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int v, e, k;


const int INF = 3000005; //10* 300000 �϶��� �ִ�
vector<pair<int,int>> adj[20005]; //��� ����
int distanceTable[20005];
priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; 

int main()
{

	//�켱���� ť�� �̿��� ���ͽ�Ʈ��� Ư�� ������ �Ÿ��� Ȯ���Ǿ����� ���θ� ���� �������� ����.
	//�켱���� ť�� ���� �Ÿ��� ���� ���� ����(0,������).

	//�ִܰŸ� ���̺��� d[������]�� =0�� �´��� Ȯ��.
	//���������� ���� �ִ� ������ Ȯ�� �� �۴ٸ� ���� 
	//���� (�Ÿ�,����) ���� �߰�
	//�켱���� ť�� ���� �Ÿ��� ���� ���� ���� �� �ִܰŸ� ���̺�� �´��� Ȯ��.
	//�Ÿ��� ���� ���� ���ҿ��� ���� �ִ� ������ Ȯ���ϰ� �ִܰŸ� ���̺� ����� ������ �۴ٸ� �����ϰ� ť�� ����.
	//�켱���� ť�� �������� �ݺ�
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> v >> e >> k;
	fill(distanceTable, distanceTable + v+1, INF);



	for (int i = 0; i < e; i++)
	{
		int u, node, w;
		cin >> u >> node >> w;
		adj[u].push_back(make_pair(w, node)); //u->v�� ���� ����ġ w
	}


	distanceTable[k] = 0; //���� ������ �Ÿ��� 0����.
	pq.push(make_pair(distanceTable[k], k)); //�켱���� ť�� ���� ���� �ֱ�.

	//�����������κ��� �̵��� �� �ִ� ��������
	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		
		//�ִܰŸ� ���̺��� ���� �켱���� ť�� ���� �ٸ��� �ǳʶڴ�.
		//Ư�� ������ ���� �Ÿ��� Ȯ����Ų ���ΰ� ���� ������. ���� ������ ���� ���� �Ÿ����� �ִܰŸ� ������ �˻縦 ��.
		if (distanceTable[cur.second] != cur.first)
			continue;

		for (auto nxt : adj[cur.second])
		{
			//������ �Ÿ��� �ִ� �Ÿ� ���̺��� �۴ٸ� ���� �� ť�� �߰�.
			if (distanceTable[nxt.second] <= distanceTable[cur.second] + nxt.first)
				continue;
			
			distanceTable[nxt.second] = distanceTable[cur.second] + nxt.first;
			pq.push(make_pair(distanceTable[nxt.second], nxt.second));
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (distanceTable[i] == INF) cout << "INF\n";
		else cout << distanceTable[i] << "\n";
	}
}