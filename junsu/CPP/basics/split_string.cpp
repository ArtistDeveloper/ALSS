#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimiter) {
	vector<string> ret;
	long long pos = 0;
	string token = "";

	while ((pos = input.find(delimiter)) != string::npos) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);

	return ret;
}

int main() {
	string s = "문자열1 문자열2 문자열3 문자열4", d = " ";
	vector<string> a = split(s, d);
	for (string b : a) cout << b << '\n';
} 
