#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    // 몸무게는 901가지 밖에 없음 100~1000 까지 >> weights 한바퀴 돌리면서 mapping 해놓고
    // for문에서 검색하면 100,000 * 1000 이라서 괜찮을 것 같음. 
    // 경우의 수는 7가지 (a = b) (2a = 3b) (2a = 4b) (3a = 2b) (3a = 4b) (4a = 2b) (4a = 3b)
    vector<long long>maps(1001,0);
    for(int i = 0; i<weights.size();i++){
        maps[weights[i]]++;
    }

    for(int i = 0; i<weights.size();i++){
        // 2배부분
        long long temp = weights[i]*2 ;
        if(temp <=1000)answer = answer + maps[temp];
        // 3/2 부분
        
        if(weights[i] % 2 == 0){
            temp = (weights[i]/2) * 3;
            if(temp <=1000)answer = answer + maps[temp];
        }
        // 4/3 부분
        if(weights[i] % 3 == 0){
            temp = (weights[i]/3) * 4;
            if(temp <=1000)answer = answer + maps[temp];
        }

    }
    //몸무게 같은애들의 경우 조합으로 처리.
    for(int i=100; i<=1000; i++) {
        if(maps[i] >= 2)
            answer += (long long)(maps[i] * (maps[i]-1)) / 2; //n개 중에 2개 뽑는 경우의 수 : n(n-1) / 2
    }

    return answer;
}

int main(){
    vector<int> weights = {100, 100, 100, 150, 150, 200, 300};
    long long answer = solution(weights);
    cout << answer;

    return 0;
}