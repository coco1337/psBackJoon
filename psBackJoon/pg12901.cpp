// https://school.programmers.co.kr/learn/courses/30/lessons/12901

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int x, y;

string w[7] = { "THU","FRI","SAT","SUN","MON","TUE","WED" };

string solution(int a, int b)
{
  int day = b;
  day += 30 * (a - 1);

  if (a <= 8 && a >= 2) 
    day += ((a - 1) % 2 == 1 ? ((a - 1) / 2) + 1 : (a - 1) / 2);
  else if (a > 8) 
    day += ((a - 1) / 2) + 1;

  if (a > 2) 
    day -= 1;

  return w[day % 7];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> x >> y;

  cout << solution(x, y);

  return 0;
}