#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;

int main()
{
	int n;
	string oper;
	map<int, int> m;
	multiset<pair<int, int>> ps_level;

	cin >> n;

	int p, l;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> l;
		ps_level.insert({ l,p });

		m.insert({ p,l });
	}
	multiset<pair<int, int>>::iterator iter;


	int oper_case;
	cin >> oper_case;
	for (int i = 0; i < oper_case; i++)
	{
		cin >> oper;
		//���� �߰�
		if (oper == "add")
		{
			cin >> p >> l;
			ps_level.insert({ l,p });
		}
		else if (oper == "recommend")
		{
			int level;
			cin >> level;
			if (level == 1)
			{
				//���� ������
				iter = --ps_level.end();
				
				cout << iter->second << endl;
			}

			else if (level == -1)
			{
				//���� �����
				iter = ps_level.begin();
				cout << iter->second << endl;
			}
		}
		else if (oper == "solved")
		{
			//������ �ش��ϴ� ���� -> map���� ���� 
			cin >> p;
			l = m[p];
			ps_level.erase({ l,p });
			m.erase(p);
		}
	}
}