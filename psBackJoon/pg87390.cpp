#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    while (left <= right) {
        answer.push_back(max((long long)floor(left/n), left++ % n) + 1);
    }
    
    
    return answer;
}