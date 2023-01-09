#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

int n;
unordered_set<string> s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string name, state;
		cin >> name >> state;
		if (state == "enter")
			s.insert(name);
		else
			s.erase(name);

	}

	vector<string> ans(s.begin(), s.end());
	sort(ans.begin(), ans.end(), greater<string>());

	for (auto i : ans)
	{
		cout << i<<'\n';
	}
}