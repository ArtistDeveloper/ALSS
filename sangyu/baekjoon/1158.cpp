#include<iostream>
#include<list>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	list<int> table;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		table.push_back(i + 1);
	}

	list<int>::iterator itr = table.begin();

	cout << "<";
	while (table.size())
	{
		for (int i = 1; i < k; i++)
		{
			if (++itr == table.end())
			{
				itr = table.begin();
				continue;
			}
		}
		if (table.size() == 1)
			cout << *itr;
		else
			cout << *itr << ", ";


		itr = table.erase(itr);


		//삭제한 자리가 end인 경우 체크해줘야함
		if (itr == table.end())
		{
			itr = table.begin();
		}


	}
	cout << ">";
	
}