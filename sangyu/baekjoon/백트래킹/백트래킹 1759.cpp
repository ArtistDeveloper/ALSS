#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int l, c;
vector<char> inputarr;
char ans[15];
void func(int st, int dp)
{
	if (dp == l)
	{
		int cnt=0;
		bool pass = false;
		for (int i = 0; i < l; i++)
		{
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
				pass = true;
			else
				cnt++;
		}
		if (pass != true || cnt<2)
			return;
		for (int i = 0; i < l; i++)
		{
			cout << ans[i];
		}
		cout << '\n';
		return;
	}

	for (int i = st; i < c; i++)
	{
		ans[dp] = inputarr[i];
		func(i + 1, dp + 1);
	}
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> l >> c;
	for (int i = 0; i < c; i++)
	{
		char input;
		cin >> input;
		inputarr.push_back(input);
	}

	sort(inputarr.begin(), inputarr.end());

	func(0, 0);
}