using namespace std;

int solution(int n) {

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int total = 0;
        int sumNum = i;
        while (total <= n)
        {
            total += sumNum;
            if (total > n)
                break;
            if (total == n)
            {
                cnt++;
                break;
            }
            sumNum++;
        }
    }
    return cnt;
}