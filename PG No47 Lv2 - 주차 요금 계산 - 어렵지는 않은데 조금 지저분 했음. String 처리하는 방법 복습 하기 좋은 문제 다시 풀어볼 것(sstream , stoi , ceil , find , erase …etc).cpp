#include<string>
#include<vector>
#include<iostream>
#include<cmath>
#include<sstream>
#include<map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    // vector배열 10000개 짜리 해놓고 거기다가 금액 계산 한다음에 출력하면 될 것 같은데
    // 계산은 car쪽에서 다하고 마지막 res에 요금 넣어 놓자.
    vector<int>cars(10000,-1);
    map<int,int>res;
    int base_t = fees[0];
    int base_f = fees[1];
    int t = fees[2];
    int f = fees[3];

    for(int i = 0 ; i < records.size(); i++){
        stringstream temp;
        temp.str(records[i]);
        string a,b,c;
        temp >> a >> b >> c ;
        a.erase(a.find(':'),1);
        int time = ((stoi(a)/100)*60)+stoi(a)%100;

        if(cars[stoi(b)] == -1){
            cars[stoi(b)] = time;
        }else{
            int p_time = time - cars[stoi(b)] ;
            
            if(res.find(stoi(b)) != res.end()){
                res[stoi(b)] += p_time;
            }else{
                res.insert(make_pair(stoi(b),p_time));
            }
            cars[stoi(b)] = -1;   

            }
        }
    for(int i= 0 ; i<cars.size();i++){
        if(cars[i]!=-1){
            res[i] = res[i] + (1439-cars[i]);
        }
    }
    for(auto temp : res){
        int fee;
        if(temp.second <= base_t){
            fee = base_f;
        }else{
            float a = (temp.second - base_t)/(float)t;
            fee = ceil(a)*f + base_f;
        }
        answer.push_back(fee);
    }

return answer;
}
    

    


int main(){
    vector<int> fees = {180, 5000, 10, 600};
    vector<string> records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    vector<int>answer = solution(fees,records);

    return 0;
}