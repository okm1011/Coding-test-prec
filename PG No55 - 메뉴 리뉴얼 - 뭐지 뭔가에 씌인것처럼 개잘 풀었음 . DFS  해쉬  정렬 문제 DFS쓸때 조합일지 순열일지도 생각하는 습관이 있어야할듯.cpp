#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
vector<string> glob_orders;
map<string,int>m;
vector<int>ch(20,0);
// i 의  max는 최대 20의 order안의 스트링 값이니까 그거 ch배열

void dfs(string st ,string temp, int max_cnt , int cnt ,int idx){
    sort(st.begin(),st.end());
    // 여기서도 꼭 sort를 해줘야하는게 order에 들어가는애들은 정렬이 안되어있어서 이게 밑에 보면 dfs를 idx 부터 시작하니까 뒤로는 안간단말이지.
    // 그렇다고 저걸 i=0부터 시작하면 XY 도나오고 YX도 나오니까 안됨.
    if(max_cnt == cnt){
        if(m.count(temp) != 0){
            m[temp]++;
        }else{
            m.insert({temp,1});
        }
        return;
    }
    for(int i = idx ; i <st.size();i++){
        if(ch[i]==0){
            ch[i] = 1;
            dfs(st,temp + st[i],max_cnt,cnt+1,i);
            ch[i] = 0;
        }
    }


}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    glob_orders = orders;
    for(int i = 0 ; i<course.size();i++){
        //여기서 course의 cnt 갯수를 받아서
        map<string,int>temp;
        m = temp;
        // m 초기화
        for(int j = 0 ; j<orders.size();j++){
            //order의 갯 수 만큼 for문 돌리는거임.
            dfs(orders[j],"",course[i],0,0);

        }
        // 여기서 dfs끝나고 나오면 map에 각각 조합에 대한 숫자가 적혀서 나올꺼임 ex) AB 1 AC 4 AD 2 ....
        vector<string>res;
        int Max = 1;
        // 주문한사람이 최소 2 여야하니까 Max는 1로시작
        for(auto it:m){
            if(it.second > Max){
                Max = it.second;
                res.clear();
                res.push_back(it.first);
            }else if(it.second == Max && !res.empty()){
                res.push_back(it.first);
            }else{

            }
        }
        for(auto s:res){
            answer.push_back(s);
        }
        m.clear();

    }


    sort(answer.begin(),answer.end());
    return answer;
}

int main(){
    vector<string> orders = {"XYZ", "XWY", "WXA"};
    vector<int> course = {2,3,4};
    vector<string>answer = solution(orders,course);
    for(int i = 0 ; i<answer.size();i++){
        cout << answer[i] << " ";
    }

    return 0;
}