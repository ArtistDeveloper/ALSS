//#include<iostream> 시간초과 코드
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
//	int n;
//	cin >> n;
//
//	vector<int> vec;
//	int h;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> h;
//		vec.push_back(h);
//	}
//
//	vector<int> s(n);
//
//	for (int i = vec.size(); i > 0; i--)
//	{
//
//		for (int j = i - 1; j > 0; j--)
//		{
//			if (vec[i - 1] < vec[j - 1])
//			{
//				s[i - 1] = j;
//				break;
//			}
//		}
//	}
//
//	for (auto i : s)
//	{
//		cout << i << ' ';
//	}
//
//
//}
// 
#include<iostream>
#include<stack>
#include <vector>
using namespace std;

int main()
{
	int n;
	stack<pair<int, int>> st;
	vector<int> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && st.top().second < vec[i])
		{
			st.pop();
		}
		if (st.empty())
		{
			cout << "0" << ' ';
		}
		else
		{
			cout << st.top().first << ' ';
		}
		st.push({ i + 1,vec[i] });
	}

	return 0;
}