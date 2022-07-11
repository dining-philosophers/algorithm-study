#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void func(vector<string> &v, string str) {
    // 알파벳 소문자화
    for(int i=0; i<str.size(); i++)
        if('A' <= str[i] && str[i] <= 'Z' )
            str[i] += 32;
    
    
    for(int i=0; i<str.size()-1; i++) {
        bool passFlag = true;
        string temp = str.substr(i,2);
        
        for(auto c : temp)
            if('z' < c or c < 'a') passFlag = false; // 자른 문자열 중 특수문자 확인
        if(!passFlag) continue;
        
        v.push_back(temp);
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> newStr1;
    vector<string> newStr2;
    
    func(newStr1, str1);
    sort(newStr1.begin(), newStr1.end());
    
    func(newStr2, str2);
    sort(newStr2.begin(), newStr2.end());
    
    int i = 0;
    int max = newStr1.size() + newStr2.size();
    int cnt = 0;
    auto temp = newStr1;
    
    if(max == 0) {
        return answer = 65536;
    } else if(newStr1.size() == 0 or newStr2.size() == 0) {
        return answer = 0;
    }
    
    if(newStr1.size() < newStr2.size()) {
        newStr1 = newStr2;
        newStr2 = temp;
    }
    
    while(i < newStr1.size()) {
        auto iter = find(newStr2.begin(), newStr2.end(), newStr1[i]);
        if(iter != newStr2.end()) {
            newStr2.erase(iter);
            cnt++;
        }
        i++;
    }

    answer = float(cnt) / float(max-cnt) * 65536;
    
    return answer;
}