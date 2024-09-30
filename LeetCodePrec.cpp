#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<int>>arr(N+1,vector<int>(N+1,10000000));
    for(int i = 0 ; i<road.size() ; i++){
        arr[road[i][0]][road[i][1]] = min(arr[road[i][0]][road[i][1]],road[i][2]);
        arr[road[i][1]][road[i][0]] = min(arr[road[i][1]][road[i][0]],road[i][2]);
    }
    for(int i = 1 ; i<=N ; i++){
        for(int j = 1 ; j<=N;j++){
            if(i==j)arr[i][j] = 0;

        }
    }
    // 이렇게 초기화 시켜놓음 i 에서 j 까지의 cost
    priority_queue<pair<int,int>>pq;
    //여기서 현재까지 cost,다음 목표 이렇게 갈꺼임 대신 cost 내림정렬이니까 -로 넣어줘야함.
    vector<int>dist(N+1,10000000);
    pq.push({0,1});

    while(!pq.empty()){
        pair<int,int>temp = pq.top();
        pq.pop();
        int cur = temp.second;
        int cost = -temp.first;
        for(int i = 1; i<=N; i++){
            if(arr[cur][i] != 10000000){
                if(dist[i] > cost + arr[cur][i]){
                    dist[i] = cost + arr[cur][i];
                    pq.push({-(cost + arr[cur][i]),i});
                }

            }
        }
    }
    for(int i = 1; i<=N;i++){
        cout << "i: " << i << "dist: "<<dist[i] << "\n";
        if(dist[i]<=K)answer++;
    }
    return answer;
}