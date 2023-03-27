#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);


	while (true)
	{
		int cnt = 0;
		vector<int> sg;

		cin >> n >> m;
		
		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < n; i++)
		{
			int s1;
			cin >> s1;
			sg.push_back(s1);
		}

		for (int i = 0; i < m; i++)
		{
			int s2;
			cin >> s2;
			if (binary_search(sg.begin(), sg.end(), s2))
				cnt++;
		}

		cout << cnt<<'\n';
	}
	
}