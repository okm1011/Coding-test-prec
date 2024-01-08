#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){

    freopen("input.txt","rt",stdin);
    priority_queue<int>pQ;
    int data;

    while(1){
        cin >> data;
        if(data == -1){
            break;
        }else if(data == 0){
            int res = 0;
            if(!pQ.empty()) res = pQ.top();
            pQ.pop();
            cout << res <<" ";
            
        }else{
            pQ.push(data);
        }
    }



    return 0;
}