#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int tc;
int main()
{
	cin >> tc;

	while (tc--)
	{
		int a, b;
		cin >> a >> b;

		vector<int> arra;
		vector<int> arrb;

		for (int i = 0; i < a; i++)
		{
			int n;
			cin >> n;
			arra.push_back(n);
		}

		for (int i = 0; i < b; i++)
		{
			int n;
			cin >> n;
			arrb.push_back(n);
		}

		sort(arra.begin(), arra.end());
		sort(arrb.begin(), arrb.end());

		int ans = 0; int idx = 0;
		for (int i = 0; i < a; i++)
		{
			while (idx < b && arra[i] > arrb[idx])
			{
				idx++;
			}
			cout << arra[i];
			ans += idx;
			cout << endl;
		}

		cout << ans<<'\n';
	}
}