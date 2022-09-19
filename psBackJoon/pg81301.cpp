// https://school.programmers.co.kr/learn/courses/30/lessons/81301

#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(string s) {
    string tmp = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            tmp = tmp + s[i];
            continue;
        }
        
        switch(s[i]) {
            case 'z' :
                tmp = tmp + '0';
                i += 3;
                break;
            case 'o' :
                tmp = tmp + '1';
                i += 2;
                break;
            case 't' :
                if (s[i + 1] == 'w') {
                    tmp = tmp + '2';
                    i+= 2;
                } else {
                    tmp = tmp + '3';
                    i += 4;
                }
                break;
            case 'f':
                if (s[i + 1] == 'o') {
                    tmp = tmp + '4';
                    i += 3;
                } else {
                    tmp = tmp + '5';
                    i += 3;
                }
                break;
            case 's' :
                if (s[i + 1] == 'i') {
                    tmp = tmp + '6';
                    i += 2;
                } else {
                    tmp = tmp + '7';
                    i += 4;
                }
                break;
            case 'e' :
                tmp = tmp + '8';
                i += 4;
                break;
            case 'n':
                tmp = tmp + '9';
                i += 3;
                break;
        }
    }
    return stoi(tmp);
}