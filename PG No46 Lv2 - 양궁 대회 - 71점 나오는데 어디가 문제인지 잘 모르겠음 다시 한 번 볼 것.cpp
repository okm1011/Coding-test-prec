#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int max_diff = 0;
vector<int>ap(11,0);
vector<int>r(11,0);
vector<int> answer;



void dfs(int arr_left , int target , int ap_sum , int r_sum){
    // 종료 부분
    if(arr_left == 0){
        while(target<11){
            if(ap[target]!=0){
                ap_sum+=10 - target;
                target ++;
            }else{
                target ++;
            }

        }
        if(r_sum>ap_sum){
            int diff = r_sum - ap_sum;
            /*
            cout << diff <<"\n";
            for(int i = 0 ; i<r.size() ; i++){
                cout << r[i] << " ";
            }
            cout << "\n";
            */
            if(diff > max_diff){
                max_diff = diff;
                answer = r;
                return;
            }else if (diff == max_diff){
                // 여기 추가 해야함.
                for(int i = 10 ; i>=0 ; i--){
                    if(r[i]>answer[i]){
                        answer = r;
                        return;
                    }else if(r[i]<answer[i]){
                        answer = answer;
                        return;
                    }else{
                        continue;
                    }
                }
            }else{
                return;
            }
        }else{
            return;
        }
    }else if(target == 10){
        // arrow 남은게 0이 아니지만 마지막 다 터는 경우.
        //cout << "arr_left : " << arr_left << "\n";
        r[10] = arr_left;
        dfs(0,10,ap_sum,r_sum);
        r[10] -= arr_left;
        return ;
    }

    // r이 이기는 경우
    //ch배열이 필요할까? 필요없을 것 같은데 for문이 아니니..
    if(arr_left - (ap[target]+1) >= 0 ){
        r[target] += ap[target]+1;
        dfs(arr_left - (ap[target]+1) , target +1,ap_sum,r_sum + (10-target));
        r[target] -= ap[target]+1;   
    }
    // r이 지는 경우
    
    dfs(arr_left,target+1,ap_sum + (10-target),r_sum); 


}


vector<int> solution(int n, vector<int> info) {
    
    // dfs로 라이언이 쏠 화살 전부 계산해서 최대 차이 && 낮은점수 맟춘순으로 정렬해서 뽑으면됨.
    // 단 경우의 수를 줄이기 위해서 각 점수판 마다 라이언이 이긴경우 vs 진경우 해서 2의 10승 1024만 탐색 -> 이러면 생각보다 탐색 범위가 넓지가 않네.
    // 하나씩 숫자올리면서 모두 탐색할시에 경우의 수가 너무 커지고 낭비가 생김. 
    ap = info;
    dfs(n,0,0,0);
    
    if(answer.empty() || max_diff == 0){
        answer.push_back(-1);
        return answer;
    }else{
        return answer;
    }
    
}

int main(){
    int n = 3;
    vector<int> info = {0,0,1,0,0,0,0,0,0,1,0};
    
    vector<int>res = solution(n,info);
    cout << max_diff;
    for(int i = 0 ; i<res.size();i++){
        cout << res[i]<<" ";
    }
    return 0;
}