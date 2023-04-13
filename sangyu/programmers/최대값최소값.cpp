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
    
    //공백이면 str을 수로 바꾸고 , 공백아 아니면 수를 채웁니다.
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