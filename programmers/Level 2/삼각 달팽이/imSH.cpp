#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector< vector<int> > snail(n);
    // 1 -> down, 2 -> right, 3 -> up
    int next_dir = 1;
    int idx = 0;
    int y_pos = -1;
    int x_pos = 0;
    // if way_cnt == 0 -> no way to go -> break loop
    int way_cnt = 3;
    
    for(int i=0; i<n; i++)
        snail[i].resize(i+1);
    
    while(way_cnt) {
        if(next_dir == 1) {
            idx++; y_pos++;
            if(y_pos > n-1 || snail[y_pos][x_pos]) { 
                next_dir = 2;
                if(way_cnt == 3) { 
                    idx--; y_pos--;
                }
                way_cnt--;
                continue;
            }
            snail[y_pos][x_pos] = idx;
            way_cnt = 3;
        } else if(next_dir == 2) {
            idx++; x_pos++;
            if(x_pos > n-1 || snail[y_pos][x_pos]) { 
                next_dir = 3;
                if(way_cnt == 3) { 
                    idx--; x_pos--;
                }
                way_cnt--;
                continue;
            }
            snail[y_pos][x_pos] = idx;
            way_cnt = 3;
        } else {
            idx++; y_pos--; x_pos--;
            if(y_pos < 1 || snail[y_pos][x_pos]) {
                next_dir = 1;
                if(way_cnt == 3) {
                    idx--; y_pos++; x_pos++;
                }
                way_cnt--;
                continue;
            }
            snail[y_pos][x_pos] = idx;
            way_cnt = 3;
        }
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            answer.push_back(snail[i][j]);
    
    
    return answer;
}