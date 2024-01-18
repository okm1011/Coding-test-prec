#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
//이거 Lec No 64 랑 비교 DFS BFS 어떤경우인지 감잡을 수 있음***********************************************


//전해야할 인자가 3개라서 pair 포기하고 class로 큐넣으려고 함
class Node{
public:
    int x;
    int y;
    int cnt;
    Node(int a,int b,int c){
        x = a;
        y = b;
        cnt = c;
    }
};

int main(){
    
    freopen("input.txt","rt",stdin);
    
    vector<vector<int>>map(9,vector<int>(9,1));
    vector<vector<int>>ch(9,vector<int>(9,0));
    // check 와 map 배열
    queue<Node>q;
    // 인자 3개 class Node의 q
    int Min = 2147000000;
    bool flag = false;
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    //방향벡터

    for(int i = 1 ; i <=7;i++){
        for(int j =1 ; j<=7;j++){
            int temp;
            cin >> temp;
            map[i][j] = temp;
        }
    }
    //초기 출발점 넣어줌 1,1 cnt 1
    q.push(Node(1,1,1));
    ch[1][1] = 1;
    //bfs cnt 1개당 전후 좌우 다 큐에 넣고 cnt++ 동장
    
    while(!q.empty()){
        if(flag == true){
            break;
        }
        int t_x = q.front().x;
        int t_y = q.front().y;
        int t_cnt = q.front().cnt;        
        for(int i = 0 ; i <4 ; i++){    
            int t_x2 = t_x + dx[i];
            int t_y2 = t_y + dy[i];
            //여기서 도착점 도달한다면 break
            if(t_x2 == 7 && t_y2 == 7){
                cout << t_cnt;
                flag = true;
                break;
            }
            
            if(0<t_x2<8&&0<t_y2<8&&ch[t_y2][t_x2] == 0&&map[t_y2][t_x2]==0){
                //cout << " t_x2: " << t_x2 << " t_y2: "<<t_y2<<" ch: " << ch[t_y2][t_x2] << " t_cnt: "<<t_cnt <<"\n";
                ch[t_y2][t_x2] = 1;
                q.push(Node(t_x2,t_y2,t_cnt+1));
            }

        }
        q.pop();
        

    }
    if(flag == false){
        cout << -1;
    }
    return 0;
}



