#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    //이거 뭔가 map으로 풀고싶은데?
    map<string,int>m;
    for(int i = 0 ; i<id_list.size();i++){
        m.insert({id_list[i],i});
    }
    //각각 번호 부여.
    vector<vector<int>>ch(1001,vector<int>(1001,0));
    //id_list max = 1000 >> 신고 check 배열 ex) 3에서 4로 checking ch[3][4]=1
    
    vector<pair<int,int>>cnt(1001,make_pair(0,0));
    //이거는 신고 / 피신고 cnt 용 pair vector배열
    
    for(int i=0 ; i<report.size();i++){
        stringstream ss;
        // 문자열 사이 공백 껴있으니까 ss로 분할?
        ss.str(report[i]);
        string temp;
        int from=-1 , to=-1;
        while(ss >> temp){
            if(from==-1){
                from = m[temp];
            }else{
                to = m[temp];
            }
        }
        if(ch[from][to]==0){
            cnt[from].first++;
            // 신고자 신고횟수(first ++)
            cnt[to].second++;
            // 피신고자 피신고횟수(second ++)
            ch[from][to] = 1;
        }
    }
    // 이제 각각 메일받는거 처리 . 정지되는놈 1개 ++ , 정지된놈 신고한놈 1개++
    vector<int>mail(id_list.size(),0);
    // 결과가 될 mail 배열


    for(int i = 0 ; i<id_list.size();i++){
        if(cnt[i].second>=k){
            for(int j = 0 ; j<id_list.size();j++){
                    if(ch[j][i]==1){
                        //i를 신고한놈.
                        mail[j]++;
                    }
            }
        }
    }
    
    answer = mail;
    
    
    return answer;
}
int main(){
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    int k = 2;
    vector<int>answer = solution(id_list,report,k);
    

    return 0;
}