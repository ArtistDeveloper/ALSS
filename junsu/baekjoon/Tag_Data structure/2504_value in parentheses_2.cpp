#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Token 
{
    int value;
    size_t pos;
};

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    vector<Token> tokens;
    tokens.push_back({ 0, '$' });
    for (size_t head = 0; head < input.size(); ++head) 
    {
        // input[head]가 '(' 또는 '['일 때
        if (input[head] == '(' || input[head] == '[') 
        {
            tokens.push_back({ 0, head }); // head를 통해 token의 각 문자의 위치를 대입한다
        }
        // input[head]가 ')' 또는 ']'일 때
        else 
        {
            const auto open_tag = (input[head] == ')' ? '(' : '[');
            // tokens에는 여는 괄호만 들어가게 된다. 그래서 open_tag와 비교할 수 있다.
            // tokens의 마지막 인덱스의 pos값을 string input의 인덱스로 사용하면 어떤 괄호인지 알아낼 수 있다.
            // 예를들어 4번 째의 괄호인 '['는 pos값을 4로 들고 있다. (0부터 string을 차례대로 셌을 때)
            // 그 뒤에 5번째 괄호인 ']'가 등장하게 되는데, 여기서 이 조건문을 살펴보면 우선 tokens벡터는 비어있지 않다.
            // 그 다음 조건문인 input[tokens.back().pos] != open_tag를 비교해야 하는데,
            // tokens.back().pos의 값은 현재 마지막에 들어온 괄호인 '['가 pos를 4로 들고 있다.
            // 그럼 input[4]가 되고, 이는 본인 자신을 가리키게 된다. input[4]는 '['이고 open_tag도 '['인 상태이므로 이 조건문은 넘어갈 수 있다.
            // 만약 input[4]가 가리키는 것은 '['인데 open_tag는 '('가 되면 틀린 케이스가 된다.
            // 그리고 이 코드에서 벡터를 썼을 뿐 사용하는 방식은 스택처럼 사용했으므로 ']'가 들어오면 '['를 만나야하고, ')'가 들어오면 '('를 만나야 하므로
            // open_tag처럼 비교할 수 있다.
            if (tokens.empty() || input[tokens.back().pos] != open_tag)
            {
                tokens.clear();
                break;
            }

            Token token = tokens.back();
            tokens.pop_back();

            const auto designated_value = (input[head] == ')' ? 2 : 3); // ')' 이면 2, ']'이면 3
            // 이 조건을 만족한다는 것은 안쪽의 닫힌 괄호라는 소리이다. 
            // 예시)
            // 두 번째로 push된 '('는 value = 0, pos = 1의 값을 들고 있다.
            // head의 값은 2인 상태인데, 해당 토큰의 위치 값에서 1을 더했을 때 head가 같다면 이것은 괄호 안쪽에서 닫힌 괄호를 뜻한다.
            // ()이렇게 붙은 것. 즉, 닫힌 괄호가 ')'이면 2를 더해주면 되고, ']'이면 3을 더해주면 된다.
            if (token.pos + 1 == head) // || tokesn.pos == head - 1
            {
                tokens.back().value += designated_value;
            }
            // 딱 붙은 괄호가 아니라는 소리다. 딱 붙은 괄호의 값은 2또는 3을 더해주면 되고, 바깥의 괄호에서는 곱을 해주면 되므로
            // 기존의 값에서 곱을 하여 넣어준다.
            else 
            {
                tokens.back().value += token.value * designated_value;
            }
        }
    }

    if (tokens.size() != 1) 
    {
        cout << "0\n";
    }
    else 
    {
        cout << tokens.back().value << '\n';
    }

    return 0;
}