#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	int test_case;
	cin >> test_case;

	int num, t_idx;


	for (int i = 0; i < test_case; i++)
	{
		queue<pair<int, int>> q; //인덱스 , 중요도
		vector<int> important(10); //중요도 
		cin >> num >> t_idx;

		for (int j = 0; j < num; j++)
		{

			int n;
			cin >> n;
			q.push(make_pair(j, n));
			important[n]++; //해당 중요도 개수 체크 

		}

		pair<int, int> go_back;
		int pop_num;
		int cnt = 0;
		while (!q.empty())
		{
			int max = 0;
			for (int i = 0; i < important.size(); i++)
			{
				if (max < i && important[i]>0)
					max = i;
			}
			if (q.front().second < max)
			{
				go_back = q.front();
				q.pop();
				q.push(go_back);
			}
			else
			{
				cnt++;
				pop_num = q.front().second;
				important[pop_num]--;

				if (t_idx == q.front().first)
				{
					cout << cnt << endl;
					break;
				}
				q.pop();
			}
		}
	}
}