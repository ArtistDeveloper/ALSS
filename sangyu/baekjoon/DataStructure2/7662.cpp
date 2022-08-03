//#include<iostream>
//#include<queue>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	
//	ios_base::sync_with_stdio(false);  cin.tie(0);
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		// 테스트케이스 
//		vector<long long> vec1;
//		vector<long long> vec2;
//		int cnt = 0;
//		
//		priority_queue<long long> pq;
//		priority_queue<long long> max_pq;
//		priority_queue<long long, vector<long long>,greater<long long>> min_pq;
//
//		int tc;
//
//		cin >> tc;
//
//		//tc번 반복 
//		for (int j = 0; j < tc; j++)
//		{
//			long long num;
//			char oper;
//
//			cin >> oper >> num;
//
//			if (oper == 'I')
//			{
//				cnt++;
//				pq.push(num);
//				max_pq.push(num);
//				min_pq.push(num);
//			}
//			else if (oper == 'D')
//			{
//				if (!pq.empty())
//				{
//					cnt--;
//					pq.pop();
//				}
//				if (num == 1)
//				{
//					if (!max_pq.empty())
//					{
//						max_pq.pop();
//					}
//				}
//				else if (num == -1)
//				{
//					if (!min_pq.empty())
//					{
//						min_pq.pop();
//					}
//				}
//			}
//		}
//		
//		int max_pq_size = max_pq.size();
//		int min_pq_size = min_pq.size();
//
//		for (int j = 0; j < max_pq_size; j++)
//		{
//			vec1.push_back(max_pq.top());
//			max_pq.pop();
//		}
//		
//		for (int j = 0; j < min_pq_size; j++)
//		{
//			vec2.push_back(min_pq.top());
//			min_pq.pop();
//		}
//
//		vector<int> buff(vec1.size() + vec2.size());
//
//		sort(vec1.begin(), vec1.end());
//		sort(vec2.begin(), vec2.end());
//
//		auto iter = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), buff.begin());
//		buff.erase(iter, buff.end());
//		
//		if (cnt<=0)
//		{
//			cout << "EMPTY"<<'\n';
//		}
//
//		else
//		{
//			cout << buff[buff.size() - 1] << ' ' << buff[0]<<'\n';
//		}
//
//	}
//}
#include<iostream>
#include<set>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	char oper;

	int t;

	cin >> t;

	int tc;
	for (int i = 0; i < t; i++)
	{
		
		cin >> tc;
		multiset<int> q;

		for (int i = 0; i < tc; i++)
		{
			int num;
			cin >> oper >> num;

			if (oper == 'I')
			{
				q.insert(num);
			}
			else if (oper == 'D')
			{
				if (q.empty())
					continue;
				else if (num == 1)
				{
					auto iter = q.end();
					iter--;
					q.erase(iter);
				}
				else if (num == -1)
				{
					q.erase(q.begin());
				}
			}
		}
		if (q.empty())
			cout << "EMPTY" << '\n';
		else
		{
			auto iter = q.end();
			iter--;
			cout << *iter << ' ' << *q.begin() << '\n';
		}
	}
}