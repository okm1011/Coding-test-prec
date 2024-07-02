#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b){
    return a.second>b.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    map<int,int>m;
    int temp = 0;
    
    for(int i = 0 ; i<s.size();i++){
        // s[i] = { or } or num
        if(s[i] == '{'){
            temp = 0;
        }else if((s[i] == ',' || s[i] == '}')&&temp!=0){
            if(m.find(temp) == m.end() ){
                m.insert({temp,1});
            }else{
                m[temp]++;
            }
            temp = 0;

        }else{
            if(temp == 0){
                temp+=s[i] - '0';
            }else{
                temp = (temp * 10) + (s[i] - '0');
            }
            

        }
        
    }
    vector<pair<int,int>>temp_vec;
    //정렬을 위한 vec

    for(auto ma:m){
        temp_vec.push_back(make_pair(ma.first,ma.second));
    }
    sort(temp_vec.begin(),temp_vec.end(),compare);
    for(int i = 0;i<temp_vec.size();i++){
        answer.push_back(temp_vec[i].first);
    }
    return answer;
}

int main(){

    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    vector<int>answer = solution(s);
    for(int i = 0 ; i<answer.size();i++){
        cout << answer[i] << " ";
    }

    return 0;
}