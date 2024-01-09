#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main(){

    freopen("input.txt","rt",stdin);
    int n;
    cin >> n;
    priority_queue<int>pQ;
    vector<pair<int,int> >data;
    int Max = -214700000;
    int sum = 0;

    for(int i = 0 ; i<n;i++){
        int value , day;
        cin >> value >> day;
        if(day > Max){
            Max = day;
        }
        data.push_back(make_pair(day,value));
        
    }

    sort(data.begin(),data.end(),greater<>());

    for(int i = Max;i>0;i--){
        for(int j = 0;j<n;j++){
            if(i == data[j].first){
                pQ.push(data[j].second);
            }
        }
        sum = sum + pQ.top();
        cout << " top: "<<pQ.top()<<"\n";
        pQ.pop();
    }
    
    cout << sum;
    return 0;
}