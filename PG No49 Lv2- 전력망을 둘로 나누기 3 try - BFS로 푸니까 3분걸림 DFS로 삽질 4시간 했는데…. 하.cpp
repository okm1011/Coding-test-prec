#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    
    // 이미 하나로 다 연결이 되어있음. 유니온앤파인드가 맞나? 음...
    // n의 최대값이라고 해봐야 100 이니까 O(n의 3제곱)도 쌉가능
    // 라인을 하나씩 끊고 라인 타면서 cnt를 올릴까? >> cnt 올리는 부분은 DFS로
    // 3,4 4,3 같은 중복이 없음 왜냐면 1<v1<v2<n 이니까
    // 진짜 뭐하니 여기는 DFS로 하면 힘든 이유가 중간에 다끊기잖아.. 근데 전체 길을 구해야하는거니까 BFS로 해야지.

    int min_diff = 1000;
    for(int i = 0 ; i<wires.size();i++){
        vector<vector<int>>temp;
        vector<int>ch(n+1,0);
        // 하나씩 간선 제거.
        for(int j = 0 ; j < wires.size();j++){
            if(i==j)continue;
            temp.push_back(wires[j]);
        }
        
        queue<int>q;
        q.push(temp[0][0]);
        int cnt = 0;
        while(!q.empty()){
            int pos = q.front();
            q.pop();
            ch[pos] = 1;
            cnt++;
            for(int j = 0; j<temp.size();j++){
                if(temp[j][0] == pos && ch[temp[j][1]] == 0){
                    q.push(temp[j][1]);
                }else if(temp[j][1] == pos && ch[temp[j][0]] == 0){
                    q.push(temp[j][0]);
                }
            }
        }
        int diff = abs((n-cnt)-cnt);
        if(diff<min_diff) min_diff = diff;


    
        
    }
    return min_diff;
}

int main(){
    int n = 9;
    vector<vector<int>> wires = {{1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9}};
    int answer = solution(n,wires);
    cout << answer;
    return 0;
}