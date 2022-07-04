#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	string str;
	stack<char> stk;
	cin >> str;
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			stk.push('(');
		}
		else if (str[i] == ')'&&str[i-1]=='(')
		{
			stk.pop();
			sum += stk.size();
		}
		//파이프 닫아 남은것.
		else
		{
			sum++;
			stk.pop();
		}
	}
	cout << sum;
}
