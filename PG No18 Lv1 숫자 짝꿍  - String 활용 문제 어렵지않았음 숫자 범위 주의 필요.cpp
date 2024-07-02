#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int>cnt(10,0);
    //X의 숫자 Scan 및 Count
    vector<int>cnt2(10,0);
    //Y와 CNT 대조 후 최종 배열 값  cnt2

    for(int i = 0 ; i<X.size();i++){
        int temp =X[i] - '0';
        cnt[temp]++;
        
    }
    for(int i = 0 ; i<Y.size();i++){
        int temp =Y[i] - '0';
        if(cnt[temp]!=0){
            cnt2[temp]++;
            cnt[temp]--;
        }
    }
    
    bool flag = true;
    for(int i = 0;i<10;i++){
        if(cnt2[i]!=0){
            flag = false;
        }
    }    
    // -1 검색

    //이걸 sum으로 더하면 int 범위 초과라서 안됨...
    string temp = "";
    // temp에다가 더해줘야함.

    for(int i = 9;i>=0;i--){
        while(cnt2[i]!=0){
            string t = to_string(i);
            if(temp=="0"&&i==0){
                cnt2[i]--;
            }else{
                temp += t;
                cnt2[i]--;
            }
            

        }
    }
    if(flag){
        answer+="-1";
    }else{
        answer +=temp;
    }

    return answer;
}
int main(){
    string X = "99999999999999999999";
    string Y = "99999999999999999999";
    string answer = solution(X,Y);
    cout << answer;

    return 0;
}