#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int len;
	int num;
	int push_count=1;
	stack<int> push_stk;
	vector<int> arr_num;
	vector<char> op;
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		cin >> num;
		while (num >= push_count)
		{
			push_stk.push(push_count);
			op.push_back('+');
			push_count++;
		}
		if (num == push_stk.top())
		{
			op.push_back('-');
			push_stk.pop();
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	for (auto i : op)
	{
		cout << i << '\n';
	}


}