#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    // 뒤에서 부터 차례로 배달, 수거 각각 더하다가 cap넘어가는 순간 그전까지로 끊어서 한번 왔다 갔다 하면될 것 같음
    // ex 만약 배달이 초과다 하면 그전까지 배달할거 실어서 출발 & 올때 가능한 만큼 수거 or 배달 하면서 귀환.

    while(1){
        int d_sum = 0;
        int p_sum = 0;
        int i = 0, j = 0;
        if(deliveries.empty()){
            break;
        }else{
            answer = answer + ((long long)deliveries.size()*2);
        }
        
        for(i;i<deliveries.size();i++){
            d_sum = d_sum + deliveries[deliveries.size()-1-i];
            p_sum = p_sum + pickups[deliveries.size()-1-j];
            if(d_sum > cap)break;
            if(p_sum > cap)break;
        }
        //둘중 하나 만족하면 나가짐.

        int back_home = i;
        int init_pack = 0;
        for(i = 0 ; i<back_home;i++){

            init_pack+=deliveries[deliveries.size()-1-i];
            
        }
        // 처음 출발 부분 . back home 만큼 가져감
        // 무조껀 가는길에 배달을 하고 올때 가져오는게 맞지 않나? cap 때문에
        // 어차피 수거때문에 back_home이 설정되었어도 init_pack 을 더 가져가는건 안되 수거해야하니까

        // 가는 길 부분. 주의할점은 배달 깔때 도 맨 뒤에서 부터 까야함. 
        for(i=0;i<back_home;i++){
            if(deliveries[deliveries.size()-1-i] > init_pack){
                deliveries[deliveries.size()-1-i] -= init_pack;
                init_pack = 0; 
            }else{
                deliveries[deliveries.size()-1-i] = 0;
                init_pack -= deliveries[deliveries.size()-1-i];
            }
            
        }
        // 오는 길 부분.
        int temp_cap = cap;
        for(i=0;i<back_home;i++){
            if(pickups[pickups.size()-1-i] > temp_cap){
                pickups[pickups.size()-1-i] -= temp_cap;
                break;
                
            }else{
                pickups[pickups.size()-1-i] = 0;
                temp_cap -= pickups[pickups.size()-1-i];
            }
            
        }
        for(i=0;i<back_home;i++){
            if(deliveries.empty())break;
            if(deliveries[deliveries.size()-1-i] == 0 && pickups[pickups.size()-1-i] ==0){
                deliveries.erase(deliveries.begin() + (deliveries.size()-1-i));
                pickups.erase(pickups.begin() + (pickups.size()-1-i));
                i--;
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