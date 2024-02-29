#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int storey) {
    int answer = 0;

    // button = -1,1,-10,10,-100,100 .....
    // 이거 걍 맨앞에서 부터 풀어도 된다... 6789의 경우 엘레베이터를 위로 올려서 빼고
    // 01234의 경우 걍 그대로 answer올리고 뺴고

    int cmp = 10;

    while(1){
        
        if(storey<(cmp/10))break;
        int tg = (storey % cmp)/(cmp/10); 
        // 646 일때 첫번째 tg = 6
        if(tg >5){
            storey += (10-tg);
            answer += (10-tg);
            //이러면 그다음자리수 +1 됬다고 생각하는거임 646 -> 650 그담에 10-tg만큼 내린거지 엘리베이터를

        }else if(tg<5){
            storey -= tg;
            answer += tg;
            //여기는 걍 그대로 tg만큼 내린거.
        }else{
            //tg==5인경우..
            int temp = (storey % cmp * 10)/(cmp); 
            if(temp >=5){
                // 그 앞자리가 5이상일때는 앞에를 올리는게 버튼 수가 더 작아짐 ex 65일때 올리면 >> 5번 70 그다음 올려서 1+3번 -> 9번 내리면 >> 5+ (60) +1 +4 10번
                // 이건 딱 5일때 어떻게할건지를 아는게 제일 중요하다..
                storey += (10-tg);
                answer += (10-tg);
            }else{
                storey += (10-tg);
                answer += (10-tg);                
            }
        }
        cmp*=10;

    }
    
    
    return answer;
}

int main(){
    int storey = 646;
    int answer = solution(storey);
    cout << answer;

    return 0;
}