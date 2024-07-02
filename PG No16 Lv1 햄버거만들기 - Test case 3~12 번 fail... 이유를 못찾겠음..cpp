#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int cnt = 0;
    queue<int>pre_cnt;
    int correct[] = {1,2,3,1};
    for(int i = 0; i<ingredient.size();i++){
        // need to be 1 , 2 , 3 ,1
        if(correct[cnt] == ingredient[i]){
            cnt++;
            if(cnt == 4){
                answer++;
                if(!pre_cnt.empty()){
                    cnt = pre_cnt.front();
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
    vector<int> ingredient = {1, 1, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1};
    int answer = solution(ingredient);
    cout << answer;
    return 0;
}