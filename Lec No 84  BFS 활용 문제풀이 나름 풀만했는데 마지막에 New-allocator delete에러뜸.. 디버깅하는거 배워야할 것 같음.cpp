#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

//넘겨야할 인자가 x,y,day 세개라서 class 필요
class Tmt{
public:
    int x;
    int y;
    int day;
    Tmt(int a, int b , int c){
        x = a;
        y = b;
        day = c;
    }
};

int main(){
    freopen("input.txt","rt",stdin);
    int m,n;
    cin >> m >> n;
    // m = j = 가로 //  n = i = 세로  
    vector<vector<int>>map(m+2,vector<int>(n+2,1));
    //얘는 어차피 익으면 1로바뀌니까 ch가 따로 필요없을 것 같음.
    //vector<vector<int>>ch(n+2,vector<int>(m+2,0));
    queue<Tmt>q;

    //상하좌우 탐색용 방향벡터
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};

    // input 읽어오는 동시에 초기 셋팅값 확인하기
    int flag = 0; // flag 1 = 값이 1인 좌표 존재
    for(int i = 1; i<=n ; i++){
        for(int j = 1 ; j <=m;j++ ){
            int temp;
            cin >> temp;
            map[i][j] = temp;
            if(map[i][j]==1){
                flag = 1;
                // x,y 좌표 및 초기 0 day 삽입 및  ch 체크  
                q.push(Tmt(j,i,0));
            }
            //cout << map[i][j];
        }
        //cout << "\n";
    }
    if(flag == 0){
        //익은게 하나도없어서 결국 아무것도 안변함 -1반환
        cout<<-1;
        return 0;
    }
    if(q.size() == n *m){
        //시작때부터 다 익어있음
        cout<<0;
        return 0;
    }
    int res = 0;
    //초기 setting된 q 활용해서 day 진행
    while(!q.empty()){
        Tmt temp = q.front();
        int t_x = temp.x ;
        int t_y = temp.y;
        int t_day = temp.day;
        res = t_day;
        cout << " t_x: " << t_x << " t_y: "<<t_y<<" t_day: "<<t_day << "\n";
        q.pop();
        
        
        for(int i = 0; i<4;i++){
            
            //cout <<" t_x+dx[i]: " <<t_x+dx[i] << " t_y+dy[i]: "<<t_y+dy[i] << " m: " << m << " n: "<<n << "map[t_x+dx[i]][t_y+dy[i]]: "<<map[t_x+dx[i]][t_y+dy[i]]<<"\n";  
            if((0<t_x+dx[i]<=m) && (0<t_y+dy[i]<=n) &&(map[t_y+dy[i]][t_x+dx[i]] == 0)){
                
                //cout <<" t_x+dx[i]: " <<t_x+dx[i] << " t_y+dy[i]: "<<t_y+dy[i] << " m: " << m << " n: "<<n<<"\n";
                map[t_y+dy[i]][t_x+dx[i]] = 1;
                q.push(Tmt(t_x+dx[i],t_y+dy[i],t_day+1));
            }
           
        }        
    }

    cout << res;

    
    return 0;
}