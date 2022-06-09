#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);	cin.tie(0);
	int n;
	cin >> n;
	
	stack<int> st;
	string str;
	int push_num;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> push_num;
			st.push(push_num);
		}

		else if (str == "top")
		{
			if (st.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << st.top() << endl;
			}
		}
		else if (str == "size")
		{
			cout << st.size() << endl;
		}
		else if (str == "pop")
		{
			if (st.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if (str == "empty")
		{
			cout << st.empty() << endl;
		}
	}

}