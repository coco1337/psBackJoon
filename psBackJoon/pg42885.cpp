// https://school.programmers.co.kr/learn/courses/30/lessons/42885

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int i = 0, j = people.size() - 1;
    int subsum = 0;
    while (i <= j) {
        subsum = people[i] + people[j];
        if (subsum > limit) {
            --j;
        } else if (subsum <= limit) {
            --j;
            ++i;
        }
        ++answer;
    }
    return answer;
}