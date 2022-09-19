// https://school.programmers.co.kr/learn/courses/30/lessons/12940

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int t = gcd(n, m);
    answer.push_back(t);
    answer.push_back(n * m / t);
    return answer;
}