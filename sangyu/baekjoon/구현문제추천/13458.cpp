#include<iostream>
#include<vector>

int main()
{
	using namespace std;
	
	//n�� ������ , i�� �����忡 �ִ� ��� Ai��.
	//������-> ��, �� 
	//�Ѱ��� - �� �����忡�� ������ �� �ִ� ������ b ��
	//�ΰ��� - '' c ��
	//�Ѱ����� 1��, �ΰ����� ������ ����.
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int space_num, super_view_num, semi_view_num;
	
	cin >> space_num;
	vector<int> space_tester_num;
	
	for (int idx = 0; idx < space_num; idx++)
	{
		int num;
		cin >> num;
		space_tester_num.push_back(num);
	}
	cin >> super_view_num >> semi_view_num;


	unsigned long cnt = 0; //�� ����.. 

	for (auto& i : space_tester_num)
	{
		i = i - super_view_num;

		cnt++;
	}

	
	for (auto& i : space_tester_num)
	{
		//�Ѱ������� ���� �� ���������� 
		if (i == 0 || i<0)
			continue;
		//�ΰ������� ������ �� �� ������
		if (i <= semi_view_num)
		{
			cnt++;
			continue;
		}
		//���������- ��ŭ ����
		int num=i / semi_view_num;
		cnt += num;

		////������ �������� �������
		//if ((i % semi_view_num) > 0 && (i % semi_view_num) < semi_view_num)
		//	cnt++;
		if (i % semi_view_num != 0 )
			cnt++;
	}

	cout << cnt;
}
