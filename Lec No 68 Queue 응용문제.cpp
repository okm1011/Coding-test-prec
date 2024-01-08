#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    freopen("input.txt","rt",stdin);
    int n , m;
    cin >>n>>m;

    queue<int>Q;
    for(int i = 1;i<=n;i++){
        Q.push(i);
    }
    while(Q.size()!=1){
        for(int i = 0 ; i<m;i++){
            if(i == m-1){
                Q.pop();
            }else{
                int temp = Q.front();
                Q.pop();
                Q.push(temp);
            }
        }
    }
    cout << Q.front();
    return 0;
}