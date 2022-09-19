// https://school.programmers.co.kr/learn/courses/30/lessons/12906

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    answer.push_back(arr[0]);
    for (auto arri: arr) {
        if (*(answer.end() - 1) != arri) {
            answer.push_back(arri);
        }
    }

    return answer;
}