//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//	int n;
//	cin >> n;
//
//	int x, y;
//	string s;
//	//�� ����
//	vector<pair<int, int>> vec;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> x>> y;
//		vec.push_back({ x,y });
//	}
//	//�ܺ� : rA + rB < d  ���� : d < |rA - rB|  
//
//	for (int i = 0; i < vec.size(); i++)
//	{
//		for (int j = i; j < vec.size(); j++)
//		{
//			if (i == j)
//				continue;
//			int d = abs(vec[i].first - vec[j].first);
//			if (vec[i].second + vec[j].second < d)
//			{
//				s = "YES";
//			}
//			else if (abs(vec[i].second - vec[j].second) > d)
//			{
//				s = "YES";
//			}
//			else
//			{
//				cout << "NO";
//				return 0;
//			}
//		}
//	}
//	cout << s << endl;
//}
#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct bracket
{
	int location;
	bool is_open;
	int id;
};
bool compare(bracket& a, bracket& b)
{
	return a.location < b.location;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	//�� -> Y���� ���� -> X�ุ �� -> �����񱳰� ��ȣ�������ȴ�. 
	//��ġ�� ������ ID�� �ش� ��ȣ�� ���� �����Ѵ�. 
	//�������� �����񱳸� �ϱ� ���ؼ��� 1. ��ȣ ��ġ�� ���� ���� , 2. ��ȣ ���� �� ���� �ذ��Ѵ�.
	int n;
	cin >> n;

	int x, r;
	vector<bracket> vec;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> r;
		
		vec.push_back({ x - r, true, i });
		vec.push_back({ x + r, false ,i });
	}
	//��ȣ ��ġ������ �������� ���� - �������� ���ϱ� ���� 
	sort(vec.begin(), vec.end(), compare);

	stack<int> st;

	for (auto  i : vec)
	{
		if (i.is_open == true)
		{
			//cout<<"is open true" << i.is_open << ' ' << i.id << ' ' << endl;
			st.push(i.id);
		}
		else if (i.is_open == false && st.top() == i.id)
		{
			//cout<<"is open false" <<i.is_open <<' ' << i.id << ' ' << endl;
			st.pop();
		}
		else
		{
			cout << "NO" << '\n';
			return 0;
		}
	}

	if (st.empty())
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	
	

}