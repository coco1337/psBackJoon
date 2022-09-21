// https://school.programmers.co.kr/learn/courses/30/lessons/92341

#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

int MAX = (24 * 60) - 1;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, pair<int, int>> m; // 차번호 : {누적, 마지막}
    set<int> s;
    int hour = 0, minute = 0;
    int c = 0;
    int car = -1;
    for (auto ri : records) {
        hour = stoi(ri.substr(0, 2));
        minute = stoi(ri.substr(3, 2));
        c = (hour * 60) + minute;  
        car = stoi(ri.substr(6, 4));
        
        if (ri[11] == 'I') {
            s.insert(car);
            if (m.find(car) == m.end()) m[car] = {0, c};
            else m[car].second = c;
        } else {
            s.erase(car);
            m[car].first += c - m[car].second;
        }
    }
    
    for (auto si : s) m[si].first += MAX - m[si].second;
    
    for (auto mi : m) {
        int fee = fees[1];
        int time = mi.second.first;
        if (time > fees[0]) {
            time -= fees[0];
            fee += ceil((float)time / fees[2]) * fees[3];
        }
        
        answer.push_back(fee);
    }
    return answer;
}