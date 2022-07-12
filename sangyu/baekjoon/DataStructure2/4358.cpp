#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cout.tie(NULL); cin.tie(NULL);

	string s;
	map<string, double> mp;

	int cnt=0;
	//EOF 입력전까지 입력받아야한다.
	while (getline(cin, s))
	{
		cnt++;
		mp[s]++;
	}

	cout << fixed;
	cout.precision(4);

	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		cout << i->first << ' ' << (i->second / cnt) * 100 << endl;
	}
}