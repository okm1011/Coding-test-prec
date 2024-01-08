#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




int main(){
    freopen("input.txt","rt",stdin);
    vector<int>map[8];
    int ch[10];
    int queue[8];
    int front = -1 , back = -1 , v;

    for(int i = 0 ; i<6;i++ ){
        int from , to;
        cin >> from >> to;
        map[from].push_back(to);
    }
    
    queue[++back] = 1;
    ch[1] = 1;
    while(front<back){
        v = queue[++front];
        cout << v;
        for(int i = 0 ; i <map[v].size();i++){
            if(ch[map[v][i]==0]){
                ch[map[v][i]==0] = 1;
                queue[++back] =map[v][i];
            }
        }
    }
    
    return 0;
}