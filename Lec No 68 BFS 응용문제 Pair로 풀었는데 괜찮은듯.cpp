#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){

    freopen("input.txt","rt",stdin);
    int h,s;
    pair<int,int> sum_pair;
    cin >> h >> s;
    
    queue<pair<int,int>>Q;
    Q.push(make_pair(h,0));
    
    int add[3] = {1,-1,5};
    int cnt = 0;
    

    while(!Q.empty()){
        sum_pair = Q.front();
        //cout << sum << " ";
        //cout << " "<<Q.front().first <<" "<<Q.front().second;
        if(sum_pair.first == s){
            cout << sum_pair.second;
            break;
        }
        Q.pop();
        for(int i = 0 ; i<3;i++){
            
            Q.push(make_pair(sum_pair.first + add[i],sum_pair.second + 1));
            
        }
        
    }
    

    return 0;
}