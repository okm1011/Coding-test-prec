#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a,int b){
    return a>b;
}
int solution(int k , vector<int>tangerine){
    int answer = 0;
    //딱 보니까 1000만 각각 pair로 counting 하고 제일 긴놈부터 answer++하면서 k 깎으면 될 듯 원소 개수대로
    vector<int>t(10000001,0);
    for(auto tan : tangerine){
        t[tan]++;
    }
    // Mapping
    sort(t.begin(),t.end(),compare);
    // 내림차순 정렬
    int i = 0;
    while(k>0){
        k = k - t[i];
        answer++;
        i++;
        
    }




    return answer;
}

int main(){
    int k = 6;
    vector<int>tangerine = {1, 3, 2, 5, 4, 5, 2, 3};
    int result = solution(k,tangerine);
    cout << result;



    return 0;
}