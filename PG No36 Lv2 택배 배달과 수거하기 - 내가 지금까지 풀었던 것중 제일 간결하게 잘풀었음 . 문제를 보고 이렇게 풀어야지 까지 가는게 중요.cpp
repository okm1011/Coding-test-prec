#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    // 딱 생각해 봤을때 어렵게 생각하지 말고 최소값을 구하는거니까 갈때 Max 로 채우고 가서 뒤에서 부터 deliveries 까고(실제로는 앞에서 부터 주는 것 처럼 되는거지)
    // 그리고 다 뿌렸으니까 트럭은 다시 빈 트럭
    // 올때도 max cap으로 뒤에서 부터 전부 수거하면서 cnt 올려서 거리 * 2 해서 answer ++ 해주면 될 것 같음.
    // 이거를 한번에 어떻게 생각하는거지 대체??
    int d_cap = 0 , p_cap = 0;
    int index = deliveries.size()-1;
    // d,p의 가장 뒤 부터 시작
    while(1){
        if(index < 0) break;
        if(deliveries[index]==0 && pickups[index]==0){
            index --;
            // 둘다 0일때는 다음칸 진행
        }else{
            if(d_cap >= deliveries[index]){
                d_cap -= deliveries[index];
                deliveries[index] = 0;
            }else{
                // 둘중 하나라도 모자르면 최대거리 *2 하고 cap 충전 어차피 각각은 따로 봐도 상관이 없음. 갈 때나 올때나 박스들을 모두 소비한다고 생각하면 되니까
                answer += (index+1) * 2;
                d_cap += cap;
                p_cap += cap;
            }
            if(p_cap >= pickups[index]){
                p_cap -= pickups[index];
                pickups[index] = 0;
            }else{
                answer += (index+1) * 2;
                d_cap += cap;
                p_cap += cap;
            }

        }

    }

    return answer;
}

int main(){
    int cap = 2;
    int n=7;
    vector<int> deliveries = {1, 0, 2, 0, 1, 0, 2};
    vector<int> pickups = {0, 2, 0, 1, 0, 2, 0};
    long long answer = solution(cap,n,deliveries,pickups);
    cout << answer;

}