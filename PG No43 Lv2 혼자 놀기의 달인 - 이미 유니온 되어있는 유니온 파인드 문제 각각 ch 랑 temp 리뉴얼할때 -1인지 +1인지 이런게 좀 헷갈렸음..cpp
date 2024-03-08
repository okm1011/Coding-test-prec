#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
    return a>b;
}

int solution(vector<int> cards) {
    int answer = 0;
    // i>> i+1번째 상자 // cards[i] 값 == 상자 내부 숫자 값
    // 유니온 - 파인드 알고리즘 활용. 서로 중복값이 없는 서로소 집합
    // point는 1번 상자 그룹 이후에 최대값을 어떻게 찾냐 이건데.
    // 이거는 그냥 1번 부터 시작해서 유니온 그룹 싹다 찾은다음에 값비교 하면 될 것 같은데
    // 이미 유니온이 되어있는거네.
    // 각각 ch 랑 temp 리뉴얼할때 -1인지 +1인지 이런게 좀 헷갈렸음.
    vector<int>ch(cards.size()+1,0);
    vector<int>res;
   
    for(int i = 0 ; i<cards.size(); i++){
        if(ch[i+1] == 0){
            int cnt = 0;
            int temp = i+1;
            ch[temp] = 1;
            cnt++;
            while(1){
                if(ch[cards[temp-1]] == 0){
                    cnt++;
                    ch[cards[temp-1]]=1;
                    temp = cards[temp-1];
                    
                    
                }else{
                    break;
                }

            }

                    
            res.push_back(cnt);
        }
        
    }
    sort(res.begin(),res.end(),compare);
    // 그룹이 하나일때 0 return
    if(res.size() == 1){
        answer = 0;
    }else{
        answer = res[0] * res[1];
    }
    
    
    

    return answer;
}

int main(){
    vector<int>cards = {8,6,3,7,2,5,1,4};
    int answer = solution(cards);
    cout << answer;
    return 0;
}
