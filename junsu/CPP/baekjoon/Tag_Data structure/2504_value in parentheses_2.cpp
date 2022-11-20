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
        // input[head]�� '(' �Ǵ� '['�� ��
        if (input[head] == '(' || input[head] == '[') 
        {
            tokens.push_back({ 0, head }); // head�� ���� token�� �� ������ ��ġ�� �����Ѵ�
        }
        // input[head]�� ')' �Ǵ� ']'�� ��
        else 
        {
            const auto open_tag = (input[head] == ')' ? '(' : '[');
            // tokens���� ���� ��ȣ�� ���� �ȴ�. �׷��� open_tag�� ���� �� �ִ�.
            // tokens�� ������ �ε����� pos���� string input�� �ε����� ����ϸ� � ��ȣ���� �˾Ƴ� �� �ִ�.
            // ������� 4�� °�� ��ȣ�� '['�� pos���� 4�� ��� �ִ�. (0���� string�� ���ʴ�� ���� ��)
            // �� �ڿ� 5��° ��ȣ�� ']'�� �����ϰ� �Ǵµ�, ���⼭ �� ���ǹ��� ���캸�� �켱 tokens���ʹ� ������� �ʴ�.
            // �� ���� ���ǹ��� input[tokens.back().pos] != open_tag�� ���ؾ� �ϴµ�,
            // tokens.back().pos�� ���� ���� �������� ���� ��ȣ�� '['�� pos�� 4�� ��� �ִ�.
            // �׷� input[4]�� �ǰ�, �̴� ���� �ڽ��� ����Ű�� �ȴ�. input[4]�� '['�̰� open_tag�� '['�� �����̹Ƿ� �� ���ǹ��� �Ѿ �� �ִ�.
            // ���� input[4]�� ����Ű�� ���� '['�ε� open_tag�� '('�� �Ǹ� Ʋ�� ���̽��� �ȴ�.
            // �׸��� �� �ڵ忡�� ���͸� ���� �� ����ϴ� ����� ����ó�� ��������Ƿ� ']'�� ������ '['�� �������ϰ�, ')'�� ������ '('�� ������ �ϹǷ�
            // open_tagó�� ���� �� �ִ�.
            if (tokens.empty() || input[tokens.back().pos] != open_tag)
            {
                tokens.clear();
                break;
            }

            Token token = tokens.back();
            tokens.pop_back();

            const auto designated_value = (input[head] == ')' ? 2 : 3); // ')' �̸� 2, ']'�̸� 3
            // �� ������ �����Ѵٴ� ���� ������ ���� ��ȣ��� �Ҹ��̴�. 
            // ����)
            // �� ��°�� push�� '('�� value = 0, pos = 1�� ���� ��� �ִ�.
            // head�� ���� 2�� �����ε�, �ش� ��ū�� ��ġ ������ 1�� ������ �� head�� ���ٸ� �̰��� ��ȣ ���ʿ��� ���� ��ȣ�� ���Ѵ�.
            // ()�̷��� ���� ��. ��, ���� ��ȣ�� ')'�̸� 2�� �����ָ� �ǰ�, ']'�̸� 3�� �����ָ� �ȴ�.
            if (token.pos + 1 == head) // || tokesn.pos == head - 1
            {
                tokens.back().value += designated_value;
            }
            // �� ���� ��ȣ�� �ƴ϶�� �Ҹ���. �� ���� ��ȣ�� ���� 2�Ǵ� 3�� �����ָ� �ǰ�, �ٱ��� ��ȣ������ ���� ���ָ� �ǹǷ�
            // ������ ������ ���� �Ͽ� �־��ش�.
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