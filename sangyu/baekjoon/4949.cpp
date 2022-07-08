#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cout.tie(NULL); cin.tie(NULL);
	vector<string> vec;
	while (true)
	{
		string s;
		getline(cin, s); //라인별 입력 
		vec.push_back(s);
		if (s[0] == '.'&& s.length()==1) // 입력종료조건
			break;
	}

	vec.pop_back(); // 입력종료조건은 뺌 

	//()(, [)]등, 반례를 생각해보기 
	for (auto i : vec)
	{
		stack<char> st;
		string anw = "yes";
		for (int j = 0; j < i.length(); j++)
		{
			if (i[j] == '[' || i[j] == '(')
			{
				st.push(i[j]);
			}
			else if ( i[j] == ']')
			{
				if (!st.empty()&& st.top() == '[')
					st.pop();
				else
				{
					anw = "no";
					break;
				}
			}
			else if ( i[j] == ')')
			{
				if (!st.empty()&&st.top() == '(')
					st.pop();
				else
				{
					anw = "no";
					break;
				}
			}
		}
		if (st.empty())
			cout << anw << '\n';
		else
		{
			anw = "no";
			cout << anw << '\n';
		}
	}
}