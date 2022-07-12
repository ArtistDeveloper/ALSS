#include<iostream>
#include<string>
#include<stack>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	//���� ǥ��� -> �����ڰ� �ǿ����� �ڿ� ��ġ��. 
	//������ �켱������ ���ÿ� �ִ°ͺ��� ������ ���� 
	//���ų� , ������ ������ �� 
	//��ȣ�� �ٷιٷ� ó�� 
	string s;
	cin >> s;

	stack<char> st;
	string new_s;
	for (int i = 0; i < s.length(); i++)
	{
		//���Ĺ��̸� ����
		if (s[i] >= 'A' && s[i] <= 'Z') 
		{
			new_s += s[i];
		}
		//��ȣ�� ���Ǿ��� ó��
		else if (s[i] == '(')
		{
			st.push(s[i]);
		}
		//�ݴ°�ȣ�� ������ 
		else if (s[i]==')')
		{
			//  ')'��  '(' �� �ƴҶ����� ��� �����ڸ� ����, �������� '('�� ����
			while (st.top() != '(')
			{
				new_s += st.top();
				st.pop();
			}
			st.pop();
		}
		else if (s[i] == '*' || s[i] == '/')
		{
			//* , /�� �켱������ ���� * , / �ۿ�����. )�� ����ȴ�. �����̱⶧���� 
			while (!st.empty() && (st.top() == '*' || st.top() == '/' || st.top()==')'))
			{
				new_s += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-')
		{
			// + , - �� ( �� �����ϰ� �켱������ ���ų� ���⶧���� pop�ؾ���. 
			while (!st.empty() && st.top()!='(')
			{
				new_s += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}

	while (!st.empty())
	{
		new_s += st.top();
		st.pop();
	}

	cout << new_s << endl;
}