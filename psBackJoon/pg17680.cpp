#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
  int answer = 0;

  vector<string> v;
  if (cacheSize == 0) return 5 * cities.size();

  for (int i = 0; i < cities.size(); ++i)
  {
    transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    auto vf = find(v.begin(), v.end(), cities[i]);
    if (vf != v.end())
    {
      v.erase(vf);
      v.push_back(cities[i]);
      answer += 1;
    }
    else
    {
      if (v.size() == cacheSize)
      {
        v.erase(v.begin());
      }

      v.push_back(cities[i]);
      answer += 5;
    }
  }

  return answer;
}