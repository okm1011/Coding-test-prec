#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

class Info{
public:
    string lan = "";
    string type = "";
    string exp = "";
    string food = "";
    int score = 0;
    Info(string a, string b , string c , string d, int e){
        lan = a;
        type = b;
        exp = c;
        food = d;
        score = e;
    }    
};


vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<Info> if_list;
    for(int i = 0 ; i < info.size() ; i++){
        stringstream ss;
        ss.str(info[i]);
        string a, b , c, d;
        int e;
        ss>>a>>b>>c>>d>>e;
        if_list.push_back(Info(a,b,c,d,e));

    }
    for(int i = 0 ; i<query.size();i++){
        int t_answer = 0;
        stringstream ss;
        ss.str(query[i]);
        string a,a_1,b,b_1,c,c_1,d;
        int e;
        ss>>a>>a_1>>b>>b_1>>c>>c_1>>d>>e;
        for(int j = 0 ; j<if_list.size();j++){
            if(!((a == "-") || (a == if_list[j].lan)))continue;
            if(!((b == "-") || (b == if_list[j].type)))continue;
            if(!((c == "-") || (c == if_list[j].exp)))continue;
            if(!((d == "-") || (d == if_list[j].food)))continue;
            if(!(e<=if_list[j].score))continue;
            t_answer++;
        }
        answer.push_back(t_answer);
    }
    return answer;
}

int main(){
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    vector<int>answer = solution(info,query);
    for(int i = 0 ; i<answer.size();i++){
        cout << answer[i] << " ";
    }
    return 0;
}