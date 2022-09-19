// https://school.programmers.co.kr/learn/courses/30/lessons/42628

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations)
{
  vector<int> answer;
  vector<int> pq;

  for (auto oi : operations)
  {
    switch (oi[0])
    {
    case 'I' :
      pq.push_back(stoi(oi.substr(2, oi.size() - 2)));
      sort(pq.begin(), pq.end());
      break;
    case 'D' :
      if (pq.size() != 0)
      {
        if (oi[2] == '1')
        {
          pq.erase(pq.end() - 1);
        }
        else
        {
          pq.erase(pq.begin());
        }
      }      
    }
  }


  if (pq.size() == 0)
  {
    answer.push_back(0);
    answer.push_back(0);
  } 
  else 
  {
    answer.push_back(pq[pq.size() - 1]);
    answer.push_back(pq[0]);
  }  

  return answer;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> v = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };

  auto ans = solution(v);

  cout << ans[0] << " " << ans[1];
  return 0;
}