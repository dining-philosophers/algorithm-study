#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

// 순열 추출
void permu(vector< vector<char> >& pri_op)
{
    vector<char> v = {'*', '+', '-'};
    int i = 0;
    do {
        for (auto it = v.begin(); it != v.end(); ++it)
            pri_op[i].push_back(*it);
        i++;
    } while (next_permutation(v.begin(), v.end()));
}
// 단순 계산
ll calc(char op, ll a, ll b)
{
    if(op == '*') return a*b;
    else if(op == '+') return a+b;
    else return a-b;
}
// 우선 순위를 반영한 최대 값 반환
ll func(vector<char> pri, vector<ll> num, vector<char> op)
{
    ll total = 0;
    int idx = 0;
    while(!op.empty())
    {
        // 현재 우선 순위에 해당하는 연산자가 있다면
        while(find(op.begin(), op.end(), pri[idx]) != op.end())
        {
            // 우선 순위에 해당하는 연산자의 인덱스 값
            int op_idx = find(op.begin(), op.end(), pri[idx]) - op.begin();
            // 연산자 왼쪽 수 = 연산자 양 옆의 수를 계산한 값 (대입)
            num[op_idx] = calc(pri[idx], num[op_idx], num[op_idx+1]);
            // 사용한 연산자 삭제
            op.erase(op.begin() + op_idx);
            // 사용한 숫자 중 오른쪽 수 삭제
            num.erase(num.begin() + op_idx+1);
        }
        idx++;
    }
  	// 반드시 0 번째 요소가 남게 되므로(피연산자 수 + 1 == 연산자 수) 이를 최종 값으로 반환
    return num[0] > 0 ? num[0] : -num[0];
}

ll solution(string expression) 
{
    ll answer = 0;

    vector<ll> num; // 피연산자 배열
    vector<char> op; // 연산자 배열
    vector < vector<char> > pri_op(6); // 연산자 순열
    permu(pri_op); // 연산자 순열화
    string temp_num;

    for(auto s : expression) // 연산자, 피연산자 배열화
    {
        if('0' <= s && s <= '9') 
        {
            temp_num += s;
        }
        else
        {
            num.push_back(stoi(temp_num));
            op.push_back(s);
            temp_num = "";
        }
    }
    num.push_back(stoi(temp_num));

    for(int i=0; i<6; i++)
    {
        auto temp = func(pri_op[i], num, op);
        if(answer < temp) answer = temp;
    }

    return answer;
}