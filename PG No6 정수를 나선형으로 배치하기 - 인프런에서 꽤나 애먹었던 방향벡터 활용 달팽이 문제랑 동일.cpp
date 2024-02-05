#include <string>
#include <vector>

using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
// 방향벡터 활용 저번에 썼던거 기억나서 씀
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    answer.resize(n,vector<int>(n,0));
    vector<vector<int>>ch(n,vector<int>(n,0));
    int x = 0 , y= 0;
    int cnt = 2;
    int i = 0;
    answer[0][0] = 1;
    ch[0][0] = 1;
    // 여기서 x,y 반대인거 주의
    while(cnt<=n*n){
        if(i==4) i = 0;
        int t_x = x + dx[i];
        int t_y = y + dy[i];
        if(0<=t_x && 0<=t_y && t_x<n && t_y<n &&ch[t_y][t_x] == 0){
            //조건에 맞다면 계속 진행 && cnt ++ 
            answer[t_y][t_x] = cnt;
            ch[t_y][t_x] = 1;
            cnt +=1;
            x = t_x;
            y = t_y;
        }else{
            //조건에 맞지 않다면 방향 전환 i++
            i = i+1;
        }
        

    }
    
    return answer;
}

int main(){
    
    vector<vector<int>>res = solution(4);
    
    
    return 0;
}