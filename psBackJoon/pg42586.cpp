#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> s(speeds.size());
    int t= 0;
    for (int i = 0; i < progresses.size(); ++i) {
        t = 100 - progresses[i];
        s[i] = t / speeds[i] + (t % speeds[i] != 0);
    }
    
    int temp = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (temp < s[i]) {
            answer.push_back(1);
            temp = s[i];
        } else {
            ++answer[answer.size() - 1];
        }
    }
    return answer;
}