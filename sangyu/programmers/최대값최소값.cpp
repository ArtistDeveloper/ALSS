#include <string>
#include <vector>
#include <iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

string solution(string s) {

    string answer = "";

    string str = "";
    vector<int> v;
    
    //�����̸� str�� ���� �ٲٰ� , ����� �ƴϸ� ���� ä��ϴ�.
    for (int i = 0; i < s.size(); i++) 
    {
        if (s[i] == ' ') 
        {
            v.push_back(stoi(str));
            str = "";
        }
        else
            str += s[i];
    }

    if (str != "") 
        v.push_back(stoi(str));

    sort(v.begin(), v.end());
    answer += to_string(v.front()) + ' ';
    answer += to_string(v.back());

    return answer;
}

int main()
{
   
    //cout << solution("1 2 3 4") << endl;
    //solution("-1 -2 -3 -4");
    cout << solution("-1 -2 -3 -4") << endl;
    //cout << solution("-1 -1") << endl;
}