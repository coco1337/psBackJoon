// https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int tmp = 0;

    for (auto si : s) {
        if (si == '(') ++tmp;
        else {
            if (tmp == 0) return false;
            --tmp;
        }
    }

    return tmp == 0;
}