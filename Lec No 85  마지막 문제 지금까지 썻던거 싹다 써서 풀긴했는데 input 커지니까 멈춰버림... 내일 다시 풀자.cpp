#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

//와 이거 진짜 어려운데 조건이 너무 많다..
int n;
int x_s,y_s,s_s; // 심바 x,y,size
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool flag = false;
vector<vector<int>>map(25,vector<int>(25,-1));

class Rb{
public:
    int x;
    int y;
    int s;
    Rb(int a,int b, int c){
        x = a;
        y = b;
        s = c;
    }
    bool operator<(const Rb&b)const{
        //return 이 true일때 Rb&b 가 위로 올라감.
        //일단 여기서 심바랑 가까운 토끼별로 분류를 할까?
        //여기서 거리별 && 위쪽 우선 && 왼쪽 우선 해서 상승큐로 들어감
        if((abs(x-x_s)+abs(y-y_s))>(abs(b.x-x_s)+abs(b.y-y_s))){
            // 기존 큐와 심바의 거리 < 새로 들어온 b와 심바의 거리
            // b 가 상승큐
            return true;
        }else if((abs(x-x_s)+abs(y-y_s))==(abs(b.x-x_s)+abs(b.y-y_s))){
            if(y>b.y){
                return true;
            }else if(y==b.y){
                if(x>b.x){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
};
void dfs(int x , int y ,int v,int r_x , int r_y,int r_v ){
    //cout<<" x: " << x << " y: " << y<< " v: " << v << " r_x: " << r_x  << " r_y: "<<r_y<<" r_v: "<<r_v <<"\n";
    if(v==r_v ){
        if(x == r_x && y==r_y){
            
            flag = true;
            return;
        }
        return ;
    }
    for(int i = 0 ; i<4;i++){
        int temp_x = x+dx[i] ;
        int temp_y = y+dy[i] ; 
        
        if(0<temp_x && temp_x <=n && 0<temp_y && temp_y<=n && map[temp_y][temp_x]<=s_s){
            
            dfs(temp_x,temp_y,v+1,r_x,r_y,r_v);
        }
    }

}
int main(){
    freopen("input.txt","rt",stdin);

    
    cin >> n;

    // 정렬은 필요없을듯 Rb 저장용 벡터
    
    int cnt = 0; // 토끼 먹은 카운트.
    int rb_cnt = 0 ; //토끼 수
    int sec = 0; // 걸린 시간 최종 결과값
    for(int i=1;i<=n;i++){
        for(int j = 1 ; j<=n;j++){
            int temp;
            cin >> temp;
            if(temp == 9){ // 심바 x,y저장 , 초기 size 2
                x_s=j;
                y_s=i;
                s_s = 2;
            }else if(temp!=0 && temp!=-1){
                rb_cnt++;
            }
            map[i][j] = temp;
        }
    }
    int n_x,n_y; // 다음 이동좌표 갱신 x,y
    map[y_s][x_s] = 0;
    for(int i = 0; i<rb_cnt;i++){ // pq써서 제일 가까운 토끼 하나 선정 for 토끼 수 만큼
        priority_queue<Rb>Pq; 
        
        for(int i=1;i<=n;i++){
            for(int j = 1 ; j<=n;j++){
                if(map[i][j]!=9 && map[i][j]!=0){
                    Pq.push(Rb(j,i,map[i][j]));
                }
         
            }
        }
        // 큐에서 하나씩 뽑아서 먹을수 있는 사이즈 인지 & 가는 길에 심바보다 큰애 없는지 확인
        while(!Pq.empty()){
            Rb temp = Pq.top();
            
            if(temp.s<s_s){
                
                int dist = abs(temp.x-x_s)+abs(temp.y-y_s);
                flag = false;
                dfs(x_s,y_s,0,temp.x,temp.y,dist);
                cout<<" i: " <<i<<" x: " << temp.x << " y: " << temp.y << " s: " << temp.s << " s_s: " <<s_s<<" flag: " <<flag <<"\n";
                if(flag){ // 사이즈 만족 && 가는길 안막히면
                    
                    sec = sec + dist ;
                    x_s = temp.x;
                    y_s = temp.y;
                    map[temp.y][temp.x] = 0;
                    // sec 증가하고 x,y 갱신.
                    cnt ++ ;
                    if(cnt == s_s){
                        s_s ++; //심바 사이즈 증가.
                        cnt = 0;
                    }
                    break;
                    //cout << " temp.x: " << temp.x << " temp.y: " << temp.y << " dist: " << dist << " sec: " << sec << " cnt: "<<cnt << " s_s: " << s_s<< "\n";
                }
            }
            Pq.pop();
        }
        
    }
    cout << sec;
    



    return 0;
}