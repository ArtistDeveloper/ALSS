#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

//N개 입력- 도감  M개 -정답맞추기  
	//숫자 ->인덱스로 해당 이름
	//이름 -> 해당인덱스 찾아주기

//vector로 푸니까 시간초과남 -> map을 이용한 find는 red-black트리기반(Balanced binary search tree -> O(logn)이라함.
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

		//숫자인지 판단 - isidgit 
		if (isdigit(input[0])) 
		{
			//숫자 -> 문자열출력
			cout << vec[stoi(input)-1] << '\n';
		}
		else
		{
			//문자 -> 숫자출력 
			auto j = collection.find(input);
			cout << j->second +1<< '\n';
		}
		
	}
}