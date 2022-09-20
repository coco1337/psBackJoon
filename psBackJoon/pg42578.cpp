// https://school.programmers.co.kr/learn/courses/30/lessons/42578

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    for (auto ci : clothes) ++m[ci[1]];
    for (auto mi : m) {
        answer *= mi.second + 1;
    }
    
    return answer - 1;
}