#include<iostream>
#include<cstring>
using namespace std;

int n;
char str[1005];
int cnt = 0;
int recusion(const char* s, int l, int r)
{
	cnt++;
	if (l>=r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recusion(s, l + 1, r - 1);
}

int isPallindrome(const char* s)
{
	return recusion(s, 0, strlen(s) - 1);
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		cout << isPallindrome(str)<<' ';
		cout << cnt << '\n';
		cnt = 0;

	}
}