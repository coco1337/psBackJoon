// https://school.programmers.co.kr/learn/courses/30/lessons/42748

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for (auto ci : commands) {
        temp.assign(array.begin() + (ci[0] - 1), array.begin() + ci[1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[ci[2] - 1]);
    }
    return answer;
}