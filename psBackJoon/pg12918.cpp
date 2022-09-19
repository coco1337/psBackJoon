// https://school.programmers.co.kr/learn/courses/30/lessons/12918

#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (!(s.size() == 4 || s.size() == 6)) return false;
    
    for (auto si : s) {
        if (!(si >= '0' && si <= '9')) return false;
    }
    return answer;
}