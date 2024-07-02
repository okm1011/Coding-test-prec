#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k , int d){
    long long answer = 0;
    // k랑 d는 100만까지(2중 for문 x)  d는 유클리드 거리 기준(대각선 피타고라스)
    // 그냥 하나씩 하면 될것같은데?
    int a = 0;
    // x축 계수.
    
   
    while((a*k <=d)){
        // 여기서 d제곱 - a*k제곱(x축) 에 루트 씌운거 정수만큼 cnt 올려주면 될 것 같은데.
        int res = 0;
        // floor로 소숫점 날릴꺼니까 res는 int로 선언
        res = floor(sqrt(pow(d,2)-(pow(a*k,2))));
        answer = answer + ((res/k)+1);

        a++;
    }
    return answer;
}
int main(){
    int k = 2;
    int d = 4;
    long long answer = solution(k,d);
    //cout << answer;



    return 0;
}