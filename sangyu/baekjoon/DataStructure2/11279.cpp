#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	//������Ÿ�� , ����ü(defalut - vector) 
	//�켱���� ť = ������ Heap�ڷᱸ�� ��� 
	//�� - ����Ʈ���� �� ���� ���������� ����Ʈ�� ����??�ε�??
	priority_queue<int, vector<int>> pq;

	int num;
	for(int i=0; i<n; i++)
	{
		cin >> num;
		pq.push(num);

		if (pq.size()==1 && num ==0)
		{
			cout << '0' << '\n';
		}
		else if(pq.size()>1 && num ==0)
		{
			cout << pq.top()<<'\n';
			pq.pop();
		}

	}

}
