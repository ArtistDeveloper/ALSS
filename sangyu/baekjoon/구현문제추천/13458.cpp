#include<iostream>
#include<vector>

int main()
{
	using namespace std;
	
	//n개 시험장 , i번 시험장에 있는 사람 Ai명.
	//감독관-> 총, 부 
	//총감독 - 한 시험장에서 감시할 수 있는 응시자 b 명
	//부감독 - '' c 명
	//총감독은 1명만, 부감독은 여려명 가능.
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


	unsigned long cnt = 0; //답 범위.. 

	for (auto& i : space_tester_num)
	{
		i = i - super_view_num;

		cnt++;
	}

	
	for (auto& i : space_tester_num)
	{
		//총감독관만 들어가서 다 샐수있으면 
		if (i == 0 || i<0)
			continue;
		//부감독관이 들어갔을때 셀 수 있으면
		if (i <= semi_view_num)
		{
			cnt++;
			continue;
		}
		//나머지경우- 몫만큼 더함
		int num=i / semi_view_num;
		cnt += num;

		////나누고 남은수가 있을경우
		//if ((i % semi_view_num) > 0 && (i % semi_view_num) < semi_view_num)
		//	cnt++;
		if (i % semi_view_num != 0 )
			cnt++;
	}

	cout << cnt;
}
