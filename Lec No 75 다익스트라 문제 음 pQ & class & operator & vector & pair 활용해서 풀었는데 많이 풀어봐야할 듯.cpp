#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


vector<pair<int,int>>map[21]; // 양방향 선 구현 -> a 연결 b (value)는 map[a]에 pair(b,value)추가 && map[b]에 pair(b,value) 추가 like from to value
int ch[21];
int dist[21];
int n , m;

class Line{
public:
    int to;
    int value;
    Line(int a, int b){
        to = a;
        value = b;
    }
    bool operator<(const Line&b)const{
        return value>b.value;
    }
};

void dfs(int v){
    priority_queue<Line>pQ;
    for(int i = 0 ; i<map[v].size();i++){
        
        if(dist[v] + map[v][i].second <= dist[map[v][i].second]){
            
            dist[map[v][i].first] = dist[v] + map[v][i].second;
        }
        pQ.push(Line(map[v][i].first,dist[map[v][i].first]));
    }
    while(!pQ.empty()){
        
        int to = pQ.top().to;
        
        pQ.pop();
        if(ch[to]==0){
            
            ch[to] = 1;

            dfs(to);
            return;
        }else{
            
        }
        
    }
    
}


int main(){
    freopen("input.txt","rt",stdin);
    fill_n(dist,sizeof(dist),2147000); // 이거 cin 전에 쓰면 n에 2147000이들어감 왜이러지 ??

    cin >> n>>m;
    

    for(int i = 0 ; i<m;i++){
        int a, b ,c;
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b,c));
        
    }
    ch[1] = 1;
    dist[1] = 0;
    dfs(1);
    
    for(int i =2;i<=n;i++){
        if(dist[i]==2147000){
            cout<<"impossible"<<" ";
        }else{
            cout << dist[i] << " ";
        }
        

    }

    return 0;
}