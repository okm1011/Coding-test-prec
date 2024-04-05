#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
bool compare(pair<char,int>a , pair<char,int>b){
    return a.first>b.first;
}
string solution(string number, int k) {
    // 그냥 조합문제인데 number.size()중 number.size() - k 조합 중 경우 중 가장 큰 수.
    // 근데 number가 100만이라서 dfs는 절대 안됨.
    // 맨 앞자리가 제일 중요한데 
    // number.size() - k 가 size일때 그러면 number[0] ~ number[size] 개 중에 제일 큰애 pick하고
    // 픽 된애 뒤에부터  size+1까지 제일 큰거 픽 ... size == number.size()면 끝.
    // 그냥 투포인트로 해보자
    string answer = "";
    int pa = 0 , pb = number.size() - k-1;

    while(pb>=0){
        int Max = -1;
        for(int i=pa;i<number.size() - pb;i++){
            if((int)number[i]>Max){
                Max = (int)number[i]; 
                pa = i+1;

                          
            } 
        }
        answer+=(char)Max;
        pb--;

    }
    return answer;
}

int main(){
    string number = "1924";
    int k = 2;
    string answer = solution(number,k);
    cout << answer;

    return 0 ;
}