#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<int> arr)
{
  int answer = 0;
  answer = arr[0];
  for (int i = 1; i < arr.size(); ++i)
  {
    answer = arr[i] * answer / gcd(arr[i], answer);
  }
  return answer;
}