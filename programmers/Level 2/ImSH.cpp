#include <string>
#include <vector>

using namespace std;

vector<int> solution(int row, int col, vector<vector<int>> qry) {
    vector<int> answer;
    vector< vector<int> > v(row, vector<int>(col, 0));
    int num = 1;
    
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            v[i][j] = num++;

    
    for(int n=0; n<qry.size(); n++) {
        int fix;
        int min = 10001;
        int tmp = v[qry[n][0]-1][qry[n][1]-1];
        if (min > tmp) min = tmp;
        
        // left
        for(int i=qry[n][0]; i<qry[n][2]; i++) {
            fix = qry[n][1]-1;
            if(min > v[i][fix])
                min = v[i][fix];
            v[i-1][fix] = v[i][fix];
        }
        // down
        for(int i=qry[n][1]; i<qry[n][3]; i++) {
            fix = qry[n][2]-1;
            if(min > v[fix][i])
                min = v[fix][i];
            v[fix][i-1] = v[fix][i];
        }
        // right
        for(int i=qry[n][2]-1; i>qry[n][0]-1; i--) {
            fix = qry[n][3]-1;
            if(min > v[i][fix])
                min = v[i][fix];
            v[i][fix] = v[i-1][fix];
        }
        // up
        for(int i=qry[n][3]-1; i>qry[n][1]-1; i--) {
            fix = qry[n][0]-1;
            if(min > v[fix][i])
                min = v[fix][i];
            v[fix][i] = v[fix][i-1];
        }
        v[qry[n][0]-1][qry[n][1]] = tmp;
        answer.push_back(min);
    }
    
    return answer;
}