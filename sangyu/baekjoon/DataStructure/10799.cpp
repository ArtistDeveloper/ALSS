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
		//������ �ݾ� ������.
		else
		{
			sum++;
			stk.pop();
		}
	}
	cout << sum;
}
