// 1번문제

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> t;

    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5, 2));
    int day = stoi(today.substr(8, 2));
    int maxDay = (year * 12 * 28) + (month * 28) + day;

    for (auto ti : terms) {
        int tm = stoi(ti.substr(2, ti.size() - 1));
        t.insert({ti[0], maxDay - (tm * 28)});
    }

    for (int i = 0; i < privacies.size(); ++i) {
        int pYear = stoi(privacies[i].substr(0, 4));
        int pMonth = stoi(privacies[i].substr(5, 2));
        int pDay = stoi(privacies[i].substr(8, 2));
        int pMaxDay = (pYear * 12 * 28) + (pMonth * 28) + pDay;

        char term = privacies[i][11];
        if (t[term] >= pMaxDay) answer.push_back(i + 1);
    }

    return answer;
}

// 2번문제
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;


long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
  long long answer = 0;
  int dt = deliveries[n - 1];
  int pt = pickups[n - 1];

  int dp =  n - 1;
  int pp = n - 1;

  while (true) {
    int gTruck = 0;
    int cTruck = 0;
    int maxDeli = 0;
    int maxPick = 0;

    while (dp >= 0) {
      if (gTruck == cap) break;
      if (deliveries[dp] == 0) {
        --dp;
        continue;
      }

      int t = gTruck + deliveries[dp];

      if (gTruck < cap) {
        maxDeli = max(maxDeli, dp + 1);
        if (t <= cap) {
          gTruck += deliveries[dp];
          deliveries[dp] = 0;
          --dp;
        } else if (t > cap) {
          deliveries[dp] -= (cap - gTruck);
          gTruck += (cap - gTruck);
        }
      }
    }

    while (pp >= 0) {
      if (cTruck == cap) break;
      if (pickups[pp] == 0) {
        --pp;
        continue;
      }
      int t = cTruck + pickups[pp];

      if (cTruck < cap) {
        maxPick = max(maxPick, pp + 1);
        if (t <= cap) {
          cTruck += pickups[pp];
          pickups[pp] = 0;
          --pp;
        } else if (t > cap) {
          pickups[pp] -= (cap - cTruck);
          cTruck += (cap - cTruck);
        }
      }
    }

    answer += max(maxDeli, maxPick) * 2;
    if (pp == -1 && dp == -1) break;
  }
  return answer;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int c = 2,n = 7;
  vector<int> d = {1, 0, 2, 0, 1, 0, 2};
  vector<int> p = {0, 2, 0, 1, 0, 2, 0};
  cout << solution(c, n, d, p);

  return 0;
}

// 3번문제


//
"UPDATE 1 1 menu", 
"UPDATE 1 2 category", 
"UPDATE 2 1 bibimbap", 
"UPDATE 2 2 korean", 
"UPDATE 2 3 rice", 
"UPDATE 3 1 ramyeon",
"UPDATE 3 2 korean", 
"UPDATE 3 3 noodle", 
"UPDATE 3 4 instant", 
"UPDATE 4 1 pasta", 
"UPDATE 4 2 italian", 
"UPDATE 4 3 noodle", 
"MERGE 1 2 1 3", 
"MERGE 1 3 1 4", 
"UPDATE korean hansik", 
"UPDATE 1 3 group", 
"UNMERGE 1 4", 
"PRINT 1 3", 
"PRINT 1 4"
