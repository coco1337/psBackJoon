// https://school.programmers.co.kr/learn/courses/30/lessons/68644

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> v((100 * 100) + 1);

vector<int> solution(vector<int> numbers)
{
  vector<int> answer;

  int sum = 0;

  for (int i = 0; i < numbers.size() - 1; ++i)
  {
    for (int j = i + 1; j < numbers.size(); ++j)
    {
      sum = numbers[i] + numbers[j];
      if (!v[sum])
      {
        v[sum] = true;
        answer.push_back(sum);
      }
    }
  }
 
  sort(answer.begin(), answer.end());
  return answer;
}

int n;
vector<int> nums;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  nums.assign(0, n);
  for (int i = 0; i < n; ++i)
  {
    cin >> nums[i];
  }

  for (auto si : solution(nums))
  {
    cout << si << ' ';
  }
  return 0;
}