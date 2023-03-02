#include <iostream>
#include <string>

using namespace std;

// 1. 함수의 정의 
// 2. base conditon
// 3. 재귀 식

// n = 1일 때 잘돌아가게 만들어보기. 그러면 n = 2, n = 3일때도 잘 돌아갈 것이다.

const string introduction = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";
const string question = R"("재귀함수가 뭔가요?")";

const string professor_answer1 = R"("잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.)";
const string professor_answer2 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
const string professor_answer3 = R"(그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.")";

const string answer_end = "라고 답변하였지.";
const string under_bar = "____";
const string base_answer = R"("재귀함수는 자기 자신을 호출하는 함수라네")";

void print_underbar(int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << under_bar;
	}
}

void func(int n, int start)
{
	if (start == n)
	{
		print_underbar(start);
		cout << question << '\n';

		print_underbar(start);
		cout << base_answer << '\n';

		print_underbar(start);
		cout << answer_end << '\n';

		return;
	}
	
	print_underbar(start);
	cout << question << '\n';
	
	print_underbar(start);
	cout << professor_answer1 << '\n';

	print_underbar(start);
	cout << professor_answer2 << '\n';

	print_underbar(start);
	cout << professor_answer3 << '\n';


	func(n, start+1);

	print_underbar(start);
	cout << answer_end << '\n';
}

int main()
{
	int n;
	cin >> n;

	cout << introduction << '\n';
	func(n, 0);

	return 0;
}
