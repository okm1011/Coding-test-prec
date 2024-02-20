#include <string>
#include <vector>
#include<algorithm>

using namespace std;
bool cmp(int a, int b){
    return a>b;
}
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0,0};
    int Min = 21470000;
    //투포인터를 활용해서 S , E을 놓고 부분수열의 합이 k이상이면 S땡기고 K이하면 E밀고 이렇게하면 되겠네...
    // 만약에 s땡겨야하는데 S==E가 될때는 둘다 하나 밀면될 것 같음.
    int s = 0 , e = 0 , sum = sequence[0];
    while(s<sequence.size() && e<sequence.size()){

        if(sum < k){
            sum = sum + sequence[++e];
        }else if(sum > k){
            sum = sum - sequence[s++];
            if(e<s){
                sum = sequence[++e];
            }
        }
        if(sum == k){
            if(e-s < Min){
                Min = e-s;
                answer[0] = s;
                answer[1] = e;
            }
            sum = sum - sequence[s++];
        }
        

    }
    
    return answer;
}
//이거를 모든 int에 대해서 더해버리면 O(N제곱)이라서 시간초과될꺼같음
//sequence 길이 max = 백만 -> n제곱은 만 넘으면 1초 초과임. nlogn으로 풀어야함 이건 max 1000만
// 이것도 일단 sort를 하고. 큰거부터 생각하는게 좋을 것 같은데 길이가 짧은 수열을 찾아야하니까? 
// 뒤에서 부터 하다가 찾으면 걔 수열 길이를 기준으로 잡고 그거 넘으면 break;
// 아니지 sort때리면 인덱스 어떻게 찾을껀데.


int main(){
    
    vector<int> sequence = {1, 1, 1, 2, 3, 4, 5};
    int k = 5;
    vector<int>answer = solution(sequence,k);



    return 0;
}