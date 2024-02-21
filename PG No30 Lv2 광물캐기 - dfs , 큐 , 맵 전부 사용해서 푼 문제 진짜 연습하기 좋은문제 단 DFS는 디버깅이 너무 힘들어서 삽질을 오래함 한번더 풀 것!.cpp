#include <vector>
#include <queue>
#include <map>
#include <iostream>


using namespace std;

int Min = 2147000;

vector<vector<int>>tired = {{1,1,1},{5,1,1},{25,5,1}};
// 피로도 미리 정의해놓은 거 

void dfs(vector<int> picks, queue<string>q,map<string,int>m,int sum){
    if(picks[0] == 0 && picks[1] == 0 && picks[2] ==0){
        //곡괭이 다썼을때
        if(sum < Min){
            Min = sum;
        }
        return;
    }
    for(int i = 0 ; i<3;i++){
        // 여기서 다 tmp로 넘겨줘야 다음 for문이 dfs에 영향을 받지않음.
        queue<string>tmp_q = q;
        vector<int>tmp_p = picks;
        int tmp_sum = sum;
        if(tmp_p[i]!=0){
            tmp_p[i]--;
            for(int j = 0 ; j<5;j++){
                tmp_sum = tmp_sum + tired[i][m[tmp_q.front()]];
                tmp_q.pop();
                if(tmp_q.empty()){
                    //미네랄 끝났을때
                    if(tmp_sum < Min){
                        Min = tmp_sum;
                    }
                    return;                    
                }
            }
            
            
            dfs(tmp_p,tmp_q,m,tmp_sum);
        }
        
    }
}
int solution(vector<int> picks, vector<string> minerals) {

    queue<string>q;
    // 순서대로 앞부터 뽑아쓰려면 큐가 편할 것 같음.
    for(int i = 0 ; i<minerals.size();i++){
        q.push(minerals[i]);
    }
    map<string,int>m;   
    m.insert({"diamond",0});
    m.insert({"iron",1});
    m.insert({"stone",2});
    // 이렇게 해놔야 맨위에 피로도 정의한거를 minerals 인자로 호출할 수 있음
    dfs(picks,q,m,0);

    return Min;
}

int main(){
    vector<int> picks = {2, 1, 0};
    vector<string> minerals = {"diamond","diamond","diamond","diamond","diamond","iron","iron","iron","iron","iron","diamond","diamond","diamond","diamond","diamond"};
    int answer = solution(picks,minerals);
    cout << answer;
    return 0;
}