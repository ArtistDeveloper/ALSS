#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	//데이터타입 , 구현체(defalut - vector) 
	//우선순위 큐 = 내부적 Heap자료구조 사용 
	//힙 - 이진트리의 한 종류 내림차순이 디폴트인 이유??인듯??
	priority_queue<int, vector<int>> pq;

	int num;
	for(int i=0; i<n; i++)
	{
		cin >> num;
		pq.push(num);

		if (pq.size()==1 && num ==0)
		{
			cout << '0' << '\n';
		}
		else if(pq.size()>1 && num ==0)
		{
			cout << pq.top()<<'\n';
			pq.pop();
		}

	}

}
