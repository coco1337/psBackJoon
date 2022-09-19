// https://school.programmers.co.kr/learn/courses/30/lessons/82612

using namespace std;

long long solution(int price, int money, int count)
{
    long long t = 0;
    for (long long i = 1; i <= count; ++i) {
        t += i * price;
    }

    if (t <= money) return 0;
    return t - money;
}