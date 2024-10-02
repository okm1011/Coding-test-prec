#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    // 와 ㅅㅂ 이거 헷갈리겠네 가로세로
    // rows 는 y의 최대값 = i = 앞의 수 // columns는 x의 최대값 = j = 뒤의 수
    vector<vector<int>>m(rows+1,vector<int>(columns+1,0));
    int cnt = 1;
    for(int i = 1; i<=rows ; i++){
        for(int j = 1; j<=columns;j++){
            m[i][j] = cnt;
            cnt++;
        }
    }

    
    for(int i =0 ; i<queries.size();i++){
        pair<int,int>st = {queries[i][0],queries[i][1]};
        pair<int,int>ed = {queries[i][2],queries[i][3]};
        //여기서 그냥 4번해버려?
        vector<int>temp;
        int row_pt = st.first;
        int col_pt = st.second;
        
        while(col_pt < ed.second){
            temp.push_back(m[row_pt][col_pt]);
            col_pt++;
        }
        while(row_pt < ed.first){
            temp.push_back(m[row_pt][col_pt]);
            row_pt++;
        }
        while(col_pt > st.second){
            temp.push_back(m[row_pt][col_pt]);
            col_pt--;
        }   
        while(row_pt > st.first){
            temp.push_back(m[row_pt][col_pt]);
            row_pt--;
        }
        int insert = temp.size()-1;
        row_pt = st.first;
        col_pt = st.second;
        
        while(col_pt < ed.second){
            m[row_pt][col_pt] = temp[insert];
            insert++;
            if(insert == temp.size())insert=0;
            col_pt++;
        }
        while(row_pt < ed.first){
            m[row_pt][col_pt] = temp[insert];
            insert++;
            if(insert == temp.size())insert=0;
            row_pt++;
        }
        while(col_pt > st.second){
            m[row_pt][col_pt] = temp[insert];
            insert++;
            if(insert == temp.size())insert=0;
            col_pt--;
        }   
        while(row_pt > st.first){
            m[row_pt][col_pt] = temp[insert];
            insert++;
            if(insert == temp.size())insert=0;
            row_pt--;
        }
        sort(temp.begin(),temp.end());
        answer.push_back(temp[0]);
    }
    
    
    return answer;
}

int main(){

    int rows = 6;
    int columns = 6;
    vector<vector<int>> queries = {{2,2,5,4},{3,3,6,6,},{5,1,6,3}};
    vector<int>answer= solution(rows,columns,queries);

    return 0;
}