#include<iostream>

int spend_time[16]={0,};
int get_pay[16]={0,};
int total_pay[16] = { 0, };

int get_max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	using namespace std;

	//n+1��° ��� -> n�ϵ��� �ִ��� ���� ���.
	//ti ���Ϸ�ð� pi ���ݾ� 
	int days;

	cin >> days;

	for (int i = 1; i <= days; i++)
	{
		cin >> spend_time[i] >> get_pay[i];
	}

	//int total_pay[16] = { 0, };�� ���������� ������ �ȵ�??

	//����ϵ���, �ٸ������ �ҽ� ������ �ִ� �ݾ׺� 
	for (int i = days; i > 0; i--)
	{
		//���Ⱓ�� �Ѵ��� Ȯ��
		//��Ż�ݾ��� ��¥���λ��ϱ� �Ѱ��ֱ��ؾ���.
		if (i + spend_time[i] > days + 1)
		{
			total_pay[i] = total_pay[i + 1];
		}
		
		//���� ����, ���ؾ���.
		else
		{
			total_pay[i] = get_max(total_pay[i + 1], total_pay[i + spend_time[i]] + get_pay[i]);
		}
	}

	cout << total_pay[1]<<endl;
	return 0;
}
