#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    //이거 걍 무적권을 쓰냐 안쓰냐로 해서 DFS로 하면 되는거 아닌가? enemy의 길이가 100만이라 안대나? - 시간 초과
    //경우의 수로 가는 순간 바로 시간 초과인데 음...
    //와 일단 다 쓰고 n이 -가 될때 지나온 애들 heap(pQ)에 넣어서 최대 애들만 무적권 써버리면서 n에 더해주면 됨.. 와
    //이런 생각은 대체 어떻게 하는걸까
    // 아이디어도 아이디어 인데 생각보다 구현에 시간이 좀 걸렸음 .
    int t_r = 0;
    priority_queue<int>pq;

    while(1){
        if(t_r>=enemy.size())break;
        if((n-enemy[t_r])>=0){
            n = n-enemy[t_r];
            pq.push(enemy[t_r]);
            t_r++;

        }else if(k>0){
            
            k--;
            // pq가 비었을때랑 enemy[t_r]이 pq 제일 큰놈 보다 클떄는 그냥 넘겨줘야함.. 이것 때문에 오래걸림
            if(pq.empty()){
                t_r++;
            }else if(enemy[t_r] > pq.top()){
                t_r++;
            }else{
                n=n+pq.top();
                pq.pop();
            }

                    
                        
            
        }else{
            break;
        }


    }



    
    answer = t_r;
    return answer;
}

int main(){
    int n = 10;
    int k = 3;
    vector<int>enemy  = {12, 11, 4, 2, 1, 5, 8, 6, 7};

    int answer = solution(n,k,enemy);
    cout << answer;

    return 0;
}