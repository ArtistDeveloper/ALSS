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

	//n+1일째 퇴사 -> n일동안 최대한 많은 상담.
	//ti 상담완료시간 pi 상담금액 
	int days;

	cin >> days;

	for (int i = 1; i <= days; i++)
	{
		cin >> spend_time[i] >> get_pay[i];
	}

	//int total_pay[16] = { 0, };왜 지역변수로 넣을땐 안됨??

	//상담일동안, 다른상담을 할시 얻을수 있는 금액비교 
	for (int i = days; i > 0; i--)
	{
		//상담기간을 넘는지 확인
		//토탈금액은 날짜별로새니까 넘겨주긴해야함.
		if (i + spend_time[i] > days + 1)
		{
			total_pay[i] = total_pay[i + 1];
		}
		
		//이전 값과, 비교해야함.
		else
		{
			total_pay[i] = get_max(total_pay[i + 1], total_pay[i + spend_time[i]] + get_pay[i]);
		}
	}

	cout << total_pay[1]<<endl;
	return 0;
}
