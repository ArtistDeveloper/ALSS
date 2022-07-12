#include<iostream>
#include<queue>
#include<functional>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;


	struct abssort
	{
		bool operator()(int a, int b)
		{
			if (abs(a) == abs(b))
				return a > b;
			return abs(a) > abs(b);

		}
	};

	priority_queue<int, vector<int>, abssort> pq;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num != 0)
			pq.push(num);
		else if (!pq.empty() && num == 0)
		{
			cout << pq.top() << '\n';
			pq.pop();
		}
		else
		{
			cout << '0' << '\n';
		}
	}

}