#include<iostream>
#include<algorithm>
#include<vector>

int n;
int x[1000001];
std::vector<int> temp_x;
std::vector<int> filter_x;
int main()
{
	using namespace std;
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		temp_x.push_back(x[i]);
	}

	sort(temp_x.begin(), temp_x.end());

	for (int i = 0; i < n; i++)
	{
		if (i == 0|| temp_x[i] != temp_x[i - 1] ) //중복제거 
		{
			filter_x.push_back(temp_x[i]);
		}
	}

	for (int i = 0; i < n; i++) //lower_bond 반환값 iter
		cout<<lower_bound(filter_x.begin(), filter_x.end(), x[i]) - filter_x.begin()<<' ';
}