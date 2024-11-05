#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int check(vector<vector<int>>arr, int x_start, int y_start , int step){
    int res = arr[y_start][x_start];
    for(int i = y_start ; i<=y_start+step; i++){
        for(int j = x_start ; j<=x_start+step ; j++){
            if(res != arr[i][j])return -1;
        }
    }
    return res;
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = {0,0};
    //bfs식으로 풀어야할듯. q에 x,y좌표로 맨 마지막 네모칸 좌표 주고.
    queue<vector<int>>q;
    int first_size = arr.size()-1;
    vector<int> first = {0,0,first_size};
    q.push(first);
    while(!q.empty()){
        vector<int> top = q.front();
        q.pop();
        int res = check(arr,top[0],top[1],top[2]);
        //s_x,s_y,e_x,e_y
        if(res != -1){ 
            answer[res]++;

        }else{
            //  15,15 >> 7,7 >> 3,3  3,3 >> 1,1
            int size = top[2];
            vector<int>temp_1 = {top[0],top[1],size/2};
            vector<int>temp_2 = {top[0]+size/2+1 , top[1] , top[2]/2};
            vector<int>temp_3 = {top[0] ,top[1] + size/2+1, top[2]/2};
            vector<int>temp_4 = {top[0]+size/2+1, top[1] + size/2+1 , top[2]/2};
            q.push(temp_1);
            q.push(temp_2);
            q.push(temp_3);
            q.push(temp_4);            
        }
    }
    return answer;
}

int main(){

    vector<vector<int>>arr = {{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}};
    vector<int>answer = solution(arr);
    cout << answer[0] << answer[1];
}