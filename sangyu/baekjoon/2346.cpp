#include<iostream>
#include<deque>
#include<vector>

using namespace std;
int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> vec;
	for (int i = 0; i < n; i++)
	{
		//�ε���, ���̿����� �����̵�
		int next_temp;
		cin >> next_temp;
		vec.push_back(make_pair(i + 1, next_temp));
	}

	int idx = 0;
	while (!vec.empty())
	{
		cout << vec.front().first << " ";
		int move = vec.front().second;
		vec.erase(vec.begin());

		if (vec.empty()) return 0;

		//�� ���� �� �ڿ� ���� -> ������ �̵� erase ������ move-1 
		if (move > 0)
		{
			for (int i = 0; i < move-1; i++)
			{
				vec.push_back(vec.front());
				vec.erase(vec.begin());
			}
		}
		//�� ���� �� �� ���� ->���� �̵� 
		else
		{
			for (int i = 0; i < abs(move); i++)
			{
				vec.insert(vec.begin(), vec.back());
				vec.erase(vec.end()-1);
			}
		}

	}
}