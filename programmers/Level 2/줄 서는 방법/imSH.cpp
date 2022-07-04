// 참고: https://velog.io/@961230/프로그래머스-줄-서는-방법-C

#include <string>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> facto_v(20);

ll facto(int n) {
    if(facto_v[n]) return facto_v[n];
    else return facto_v[n] = n * facto(n-1);
}

vector<int> solution(int n, long long k) {
    facto_v[0] = facto_v[1] = 1;
    vector<int> man(n);
    vector<int> answer;
    
    for(int i=0; i<n; i++) 
        man[i] = i+1;
    
    while(answer.size() != n-1) {
        ll tmp = facto(n-answer.size()-1);
        int idx = (k-1) / tmp;
        answer.push_back(man[idx]);
        man.erase(man.begin()+idx);
        k %= tmp;
        if(k == 0)
            k = tmp;
    }
    
    answer.push_back(man[0]);
    return answer;
}