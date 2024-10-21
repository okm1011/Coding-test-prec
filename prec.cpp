#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    // 이건 기본적으로 스택이아니고 큐 아닌가 다리 올라가서 빠져나가는데 2초인거네 음
    // 일단 작은걸로 줄세워서 여러개 할 수 있나 봐야하는거아닌가
    // 대기 입장에서는 디큐에 올라가있는거 + 1 이 갯수보다작고 총무게보다 작으면 넣는거고
    // 디큐 입장에서는 매초 count올리고 count 1이면 pop 해주면 될 거 같은데

    deque<pair<int,int>>bridge;
    int index = 0;
    int sum_weight = 0;
    int presize_bridge = 0;
    while(1){
        // while 탈출 조건은 브릿지 비어있고 대기 트럭 없으면 break;
        if(bridge.empty() && index == truck_weights.size())break;
        answer++;
        while(index<truck_weights.size()){
            if(bridge.size() < bridge_length && sum_weight + truck_weights[index] <= weight){
                bridge.push_back({truck_weights[index],0});
                sum_weight+=truck_weights[index];
                index++;
                break;
            }else{
                break;
            } 
        }
        deque<pair<int,int>>::iterator iter;
        for(iter = bridge.begin() ; iter != bridge.end() ; iter++){
            iter->second++;   
            if(iter->second == bridge_length){
                auto front = bridge.front();
                bridge.pop_front();
                sum_weight-=front.first;
            }
        }
        
    }
    
    
    return answer+1;
}
int main(){
    vector<int> truck_weights = {7,4,5,6};
    int answer =solution(2,10,truck_weights);

    return 0;
}