#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

//N�� �Է�- ����  M�� -������߱�  
	//���� ->�ε����� �ش� �̸�
	//�̸� -> �ش��ε��� ã���ֱ�

//vector�� Ǫ�ϱ� �ð��ʰ��� -> map�� �̿��� find�� red-blackƮ�����(Balanced binary search tree -> O(logn)�̶���.
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	map<string, int> collection;
	vector<string> vec;
	int n, m;

	cin >> n >> m;

	string name;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		collection.insert({ name,i });
		vec.push_back(name);
	}
	
	string input;
	for (int i = 0; i < m; i++)
	{
		cin >> input;

		//�������� �Ǵ� - isidgit 
		if (isdigit(input[0])) 
		{
			//���� -> ���ڿ����
			cout << vec[stoi(input)-1] << '\n';
		}
		else
		{
			//���� -> ������� 
			auto j = collection.find(input);
			cout << j->second +1<< '\n';
		}
		
	}
}