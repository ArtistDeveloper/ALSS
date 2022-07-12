#include<iostream>
#include<queue>
using namespace std;

int main()
{
	queue<int> q;
	int num;
	int storage;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		q.push(i+1);
	}

	while (q.size() > 1)
	{
		q.pop();
		//storage = q.front();
		q.push(q.front());
		q.pop();
		//q.push(storage);
	}

	cout<<q.front();
}