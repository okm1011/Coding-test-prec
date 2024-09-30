#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    // bfs도 애매 dfs도 애매함 이럴때는 dp로 푸는거지
    vector<vector<int>>arr (N+1,vector<int>(N+1,1000000));
    for(int i = 1 ; i<=N;i++){
        for(int j = 1; j<=N;j++){
            if(i==j)arr[i][j] = 0;              
        }
    }
    // i 에서 j로 가는데 자기 자신이면 값 0임.
    for(int i = 0 ; i<road.size() ; i++){
        arr[road[i][0]][road[i][1]] = min(arr[road[i][0]][road[i][1]],road[i][2]);
        arr[road[i][1]][road[i][0]] = min(arr[road[i][1]][road[i][0]],road[i][2]);
    }
    // 처음 주어진 애들로 초기화 >> 한번에 가는경우
    
    //이제 3중 포문으로 플로이드 와샬 하는거임 각 중간노드 k 일때 i에서 j 가는거 갱신하는거지 >> DP지
    // 근데 이게 중간 노드가 여러개면 안되는거아닌가??
    for(int k = 1; k<=N ; k++){
        for(int i = 1; i<=N ; i++){
            for(int j = 1; j<=N;j++){
                arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }

    for(int i = 1 ; i<=N;i++ ){
        if(arr[1][i] <= K)answer++;
    }

    return answer;
}