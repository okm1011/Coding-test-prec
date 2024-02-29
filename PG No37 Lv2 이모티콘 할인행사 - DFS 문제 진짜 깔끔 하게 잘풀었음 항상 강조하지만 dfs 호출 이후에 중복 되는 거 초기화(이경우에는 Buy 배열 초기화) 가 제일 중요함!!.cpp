#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int,int>> res;
// 결과값 저장배열 여기서 앞쪽 플러스 가입자 내림차순 정렬해서 맨위 뽑아내면 그게 답
int percent[] = {10,20,30,40};
bool compare1(pair<int,int>a,pair<int,int>b){
    return a.first>b.first ;
}
bool compare2(pair<int,int>a,pair<int,int>b){
    return a.second>b.second ;
}
void dfs(vector<vector<int>> users, vector<int> emoticons, int v,vector<int> buy){
    if(v == emoticons.size()){
        int plus = 0;
        int sum = 0;
        // 마지막 다 끝나고 buy update된 걸 기반으로 res에 값 삽입
        for(int i = 0 ; i<buy.size();i++){
            if(buy[i]>=users[i][1]){
                plus ++;
            }else{
                sum += buy[i];
            }
        }
        res.push_back(make_pair(plus,sum));
        return;
    }
    for(int i = 0 ; i<4;i++){
        int emo_price = (emoticons[v]/10)* (10-(percent[i]/10));
        vector<int>buy_temp = buy; 
        for(int j = 0;j<users.size();j++){
            if(users[j][0]<=percent[i]){
                buy[j] += emo_price;
                // 할인율 보다 크다면 샀다고 생각하고 buy 업데이트!
            }
        }
        dfs(users,emoticons,v+1,buy);
        buy = buy_temp;
        // buy 배열은 다시 처음으로 돌려놔줘야함 dfs 호출 끝난 후에 이게 제일 중요함
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    // 할인률은 10,20,30,40 중 하나 >> 다해봐야지뭐 dfs로 어차피 이모티콘 max 길이 = 7 이니까
    vector<int> buy(users.size(),0);
    dfs(users,emoticons,0,buy);
    sort(res.begin(),res.end(),compare1);
    vector<pair<int,int>> res2;
    // 한번더 정렬 second도 커야하니까
    for(int i = 0; i<res.size();i++){
        if(res[i].first == res[0].first){
            res2.push_back(res[i]);
        }else{
            break;
        }
    }
    sort(res2.begin(),res2.end(),compare2);
    
    answer.push_back(res2[0].first);
    answer.push_back(res2[0].second);

    return answer;
}

int main(){
    vector<vector<int>> users = {{40, 2900}, {23, 10000}, {11, 5200}, {5, 5900}, {40, 3100}, {27, 9200}, {32, 6900}};
    vector<int> emoticons = {1300, 1500, 1600, 4900};
    vector<int> answer = solution(users,emoticons);

    for(int i = 0 ; i<answer.size();i++){
        cout << answer[i] << " ";
    }
    return 0;
}