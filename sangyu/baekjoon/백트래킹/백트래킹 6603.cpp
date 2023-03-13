#include<iostream>
#include<vector>
using namespace std;

int s[13];
int k;
int ans[6];

void func(int st,int dp)
{
	if (dp == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << ans[i] << ' ';
		}
		cout <<endl;
		return;
	}
	
	//깊이는 그대로인 상태에서 i를 늘려줍니다.
	for (int i = st; i < k; i++)
	{
		ans[dp] = s[i];
		func(i+1,dp + 1);
	}
}
int main()
{
	while (true)
	{
		cin >> k;
		if (k == 0)
			break;

		for (int i = 0; i < k; i++)
		{
			cin >> s[i];
		}

		func(0,0);
		cout << '\n';
	}
}