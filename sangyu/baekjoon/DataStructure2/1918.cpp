#include<iostream>
#include<string>
#include<stack>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	//후위 표기법 -> 연산자가 피연산자 뒤에 위치함. 
	//연산자 우선순위가 스택에 있는것보다 높으면 넣음 
	//같거나 , 낮은게 나오면 뺌 
	//괄호는 바로바로 처리 
	string s;
	cin >> s;

	stack<char> st;
	string new_s;
	for (int i = 0; i < s.length(); i++)
	{
		//알파뱃이면 넣음
		if (s[i] >= 'A' && s[i] <= 'Z') 
		{
			new_s += s[i];
		}
		//괄호면 조건없이 처리
		else if (s[i] == '(')
		{
			st.push(s[i]);
		}
		//닫는괄호면 빼야함 
		else if (s[i]==')')
		{
			//  ')'는  '(' 가 아닐때까지 모든 연산자를 빼고, 마지막에 '('를 뺀다
			while (st.top() != '(')
			{
				new_s += st.top();
				st.pop();
			}
			st.pop();
		}
		else if (s[i] == '*' || s[i] == '/')
		{
			//* , /는 우선순위가 같은 * , / 밖에없음. )는 없어도된다. 곱셈이기때문에 
			while (!st.empty() && (st.top() == '*' || st.top() == '/' || st.top()==')'))
			{
				new_s += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-')
		{
			// + , - 는 ( 를 제외하곤 우선순위가 같거나 낮기때문에 pop해야함. 
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