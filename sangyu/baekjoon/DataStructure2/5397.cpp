#include<iostream>
#include<string>
#include<list>
using namespace std;

int main()
{
	//백스페이스 -> -
	//커서 바로 앞에 글자 존재 ->  < ,> 움직일수있으면 왼,오로 움직임
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;

	string s;
	

	for (int i = 0; i < n; i++)
	{
		list<char> lt;
		auto curser = lt.begin();

		cin >> s;

		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '<' && curser != lt.begin())
			{
				curser--;
			}
			else if (s[j] == '>' && curser != lt.end())
			{
				curser++;
			}
			else if (s[j] == '-' && curser != lt.begin())
			{
				curser--;
				curser = lt.erase(curser);
			}
			else if(s[j]!= '<' &&s[j] !='>' && s[j] !='-')
			{
				lt.insert(curser, s[j]);
			}
			
		}

		for (auto z : lt)
			cout << z;

		cout << '\n';


	}

}