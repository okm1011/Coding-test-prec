#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Line{
public:
    int from;
    int to;
    int value;
    Line(int a , int b , int c){
        from = a;
        to = b;
        value = c;
    }

};
int main(){
    int dist[100];
    for(int i = 0;i<100;i++){
        dist[i] = 2147000000;
    }
    freopen("input.txt","rt",stdin); 
    int n , m;
    cin >> n >> m;
    vector<Line>map;
    
    for(int i = 0 ; i<m;i++){
        int a,b,c;
        cin >> a >>b >> c;
        map.push_back(Line(a,b,c));
    }
    
    int s,e;
    cin >> s >> e;
    dist[s] = 0;
    
    // 벨만포드 알고리즘은 간선을 대상으로 그냥 n-1번만큼 모든 간선에 대해 가중치를 생각해보는거
    // 1번에 갈수있는 and 2번에 갈수있는 .... n-1번째 갈 수 있는 해서 최솟값을 dist에 저장.
    // 1번 2번 3번만에 갈수있는거 구분은 dist가 변경이 안되어있는애들은 건너뜀 중요
    for(int i = 1 ; i<n;i++){
        for(int j = 0;j<map.size();j++){
            int u = map[j].from;
            int v = map[j].to;
            int w = map[j].value;

            if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
                dist[v] = dist[u]+w;
            }
        }
    }
    // 이렇게 하면 최종 값이 나오는데 음의 사이클이 생긴다면 계속 갱신이 될 것이기 떄문에 밑에 마지막 n번쨰 한번 더해서 갱신되는게 있는지 확인해야함.
    // 기억 안나면 강의한번 다시 확인할 것
    for(int i = 0;i<map.size();i++){
        int u = map[i].from;
        int v = map[i].to;
        int w = map[i].value;

        if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
            cout << "-1\n"; // 갱신되면 음의 사이클 존재하는거니까 [n번쨰 이후로도 최소값이 계속 감소] -1 출력 후 종료
            exit(0);
        }
    }
    cout << dist[e];
    return 0;
}