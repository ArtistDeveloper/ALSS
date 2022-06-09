#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string str;
	for (int i = 0; i < n; i++)
	{
		string a = "YES";
		stack<char> st;

		cin >> str;
		
		for (auto i : str)
		{
			if (i == '(')
			{
				st.push(i);
			}
			else if (!st.empty() && i == ')' && st.top() == '(')
			{
				st.pop();
			}
			else
			{
				a = "NO";
				break;
			}
		}
		if (!st.empty())
			a = "NO";
		cout << a << endl;
	}
}