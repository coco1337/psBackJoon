#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s)
{
  vector<int> answer;

  int p = s / n;

  if (n > s)
  {
    answer.push_back(-1);
    return answer;
  }

  int q = s % n;
  int i = 0;
  for (; i < n - q; ++i)
  {
    answer.push_back(p);
  }
  for (; i < n; ++i)
  {
    answer.push_back(p + 1);
  }
  return answer;
}