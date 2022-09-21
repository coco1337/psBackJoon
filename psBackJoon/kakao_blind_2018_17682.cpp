// https://school.programmers.co.kr/learn/courses/30/lessons/17682

#include <string>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> scores;
    int score = 0;
    int i = 0;
    while (i < dartResult.size()) {
        if (dartResult[i] >= '0' && dartResult[i] <= '9') {
            if (dartResult[i] == '1') {
                if (dartResult[i + 1] == '0') {
                    score = 10;
                    ++i;
                } else score = 1;
            } else score = dartResult[i] - '0';
            
            scores.push_back(score);
        }
        else if (dartResult[i] == 'S') {
            // scores[scores.size() - 1] = pow(scores[scores.size() - 1], )
        } else if (dartResult[i] == 'D') {
            scores[scores.size() - 1] = pow(scores[scores.size() - 1], 2);
        } else if (dartResult[i] == 'T') {
            scores[scores.size() - 1] = pow(scores[scores.size() - 1], 3);
        } else if (dartResult[i] == '*') {
            scores[scores.size() - 1] *= 2;
            if (scores.size() > 1) scores[scores.size() - 2] *= 2;
        } else if (dartResult[i] == '#') {
            scores[scores.size() - 1] = -scores[scores.size() - 1];
        }
        
        ++i;
    }
    
    return accumulate(scores.begin(), scores.end(), 0);
}