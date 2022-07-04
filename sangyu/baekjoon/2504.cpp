#include<iostream>
#include <string>
#include <stack>

using namespace std;


int main()
{
	string str;
	cin >> str;
	stack<char> st;
	int anw = 0, temp = 1;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			temp *= 2;
			st.push('(');
		}
		else if (str[i] == '[')
		{
			temp *= 3;
			st.push('[');
		}
		else if (str[i] == ')')
		{
			if (st.empty()||st.top()!='(')
			{
				anw = 0; 
				break;
			}
			if(str[i-1] =='(')
			{
				anw += temp;
				temp /= 2;
				st.pop();
			}
			else
			{
				temp /= 2;
				st.pop();
			}
		}
		else if (str[i] == ']')
		{
			if(st.empty() || st.top() != '[')
			{
				anw = 0;
				break;
			}
			if(str[i-1]=='[')
			{
				anw += temp;
				temp /= 3;
				st.pop();
			}
			else
			{
				temp /= 3;
				st.pop();
			}
		}
	}
	if (!st.empty())
	{
		anw = 0;
	}
	cout << anw;
}