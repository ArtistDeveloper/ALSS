#include<iostream>
#include<stack>

using namespace std;

int matchingalpa[26];

int main()
{
	char operate;
	stack<double> numStk;

	int n;
	cin >> n;

	string inputStr;
	cin >> inputStr;

	for (int i = 0; i < n; i++)
	{
		cin >> matchingalpa[i];
	}


	for (int i = 0; i < inputStr.size(); i++)
	{
		if (inputStr[i] == '+' || inputStr[i] == '*' || inputStr[i] == '/' || inputStr[i] == '-')
		{
			double rightnum = numStk.top();
			numStk.pop();

			double leftnum = numStk.top();
			numStk.pop();

			if (inputStr[i] == '+')
				numStk.push(leftnum + rightnum);

			else if (inputStr[i] == '-')
				numStk.push(leftnum - rightnum);

			else if (inputStr[i] == '*')
				numStk.push(leftnum * rightnum);

			else
				numStk.push(leftnum / rightnum);
		}
		else
		{
			//'A' -> 0¹øÂ° 'B' ->1¹ø
			numStk.push(matchingalpa[inputStr[i] - 'A']);
		}
	}

	double output = numStk.top();
	cout << fixed;
	cout.precision(2);
	cout << output << endl;
}