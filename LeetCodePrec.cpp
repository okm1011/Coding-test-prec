
#include <iostream>
#include <vector>
using namespace std;
vector<int> solution(int n) {
    vector<int> answer;
    if(n==1){
        answer.push_back(1);
        return answer;
    }
    //? 이거 쉬운거아닌가
    vector<vector<int>>arr;
    int sum = 0;
    int cnt = 0;
    while(cnt < n){
        cnt++;
        sum+=cnt;
        vector<int>temp(cnt,0);
        arr.push_back(temp);
    }
    // arr만들기 이제 어떻게 채워야할지 생각해봐야함.
    int x = 0 ;
    int y = 0 ;
    int num = 1;
    int direc = 0;
    int dx[] = {0,1,-1};
    int dy[] = {1,0,-1};


    while(num<=sum){
        arr[y][x] = num;
        num++;
        int temp_x = x + dx[direc];
        int temp_y = y + dy[direc];
        //cout << "x: " << temp_x << " y: "<<temp_y << "\n";

        if(temp_y<0 || temp_y>=arr.size() || temp_x<0 || temp_x >= arr[y].size() || arr[temp_y][temp_x] != 0 ){
            direc = (direc + 1) % 3; 
            temp_x = x + dx[direc]; 
            temp_y = y + dy[direc];  
        }
        x = x+dx[direc];
        y = y+dy[direc];
        
    }
    
    
    for(int i = 0 ; i<arr.size();i++){
        for(int j = 0 ; j < arr[i].size();j++){
            answer.push_back(arr[i][j]);
        }
    }

    
    return answer;
}
