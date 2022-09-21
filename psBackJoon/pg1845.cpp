// https://school.programmers.co.kr/learn/courses/30/lessons/1845

#include <vector>
#include <set>
#include <cmath>
using namespace std;

int solution(vector<int> nums)
{
    set<int> s(nums.begin(), nums.end());
    return min(s.size(), nums.size() / 2);
}