#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int cnt = 0;
    stack<int>pre_cnt;
    // 아니지 여기서는 큐를쓰는게 아니고 스택을 써야지... 선입 후출이니까 Pre cnt는
    int correct[] = {1,2,3,1};
    for(int i = 0; i<ingredient.size();i++){
        // need to be 1 , 2 , 3 ,1
        if(correct[cnt] == ingredient[i]){
            cnt++;
            if(cnt == 4){
                answer++;
                if(!pre_cnt.empty()){
                    cnt = pre_cnt.top();
                    pre_cnt.pop();
                }else{
                    cnt = 0;
                }

            }
        }else{
            if(cnt!=0){
                // cnt가 0인 경우는 어차피 made가 안됨.
                pre_cnt.push(cnt);
                i--;
                // 아닐경우 다시 하나 뒤에서 부터 봐야함.
                cnt = 0;
            }

        }
    }
    return answer;
}
int main(){
    vector<int> ingredient = {1, 2, 2, 3, 1};
    int answer = solution(ingredient);
    cout << answer;
    return 0;
}