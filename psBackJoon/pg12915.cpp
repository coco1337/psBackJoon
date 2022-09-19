// https://school.programmers.co.kr/learn/courses/30/lessons/12915

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<char, string>> v(strings.size(), pair<char, string>());
    for (int i = 0; i < strings.size(); ++i) {
        v[i].first = strings[i][n];
        v[i].second = strings[i];
    }
    
    sort(v.begin(), v.end());
    
    for (auto vi : v) {
        answer.push_back(vi.second);
    }
    return answer;
}