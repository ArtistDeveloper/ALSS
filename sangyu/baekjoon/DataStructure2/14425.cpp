#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	int n, m;
	string mach;

	cin >> n >> m;

	map<string,int> mp;
	for (int i = 0; i < n; i++)
	{
		cin >> mach;
		mp.insert({ mach,i });
	}

	string input;
	int cnt=0;
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		auto j = mp.find(input);

		//find�� iterator�� ��ȯ��, �߰ߵ��� ������ end()�� ��ȯ��.
		if (j != mp.end())
		{
			cnt++;
		}
		else
			continue;
	}

	cout << cnt;
}