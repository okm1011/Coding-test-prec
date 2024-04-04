#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

bool compare(pair<int,int>a, pair<int,int>b){
    return a.first > b.first;
}
int solution(vector<int> people, int limit) {
    int answer = 0;
    // 시간초과 떳음 이런거 보통 몸무게 별로 cnt올려버리던데 정수니까
    // 그래봐야 범위 40~240임 50000보다 훨씬 적음.
    map<int,int>weight;
    for(int i = 0 ; i < people.size();i++){
        if(weight.find(people[i])==weight.end()){
            weight.insert({people[i],1});
        }else{
            weight[people[i]]++;
        }
    }
    vector<pair<int,int>>a_m;
    for(auto w : weight){
        a_m.push_back(make_pair(w.first,w.second));
    }
    sort(a_m.begin(),a_m.end(),compare);
    // 이거 이후에는 정렬된 몸무게별 인원이 나올거임. 여기서 투포인트??
    
    int pa = 0 , pb = a_m.size()-1;
    while(pa<=pb){
        if(pa==pb){
            if(a_m[pa].first > limit/2){
                answer += a_m[pa].second;
            }else{
                if(a_m[pa].second % 2 ==0){
                    answer += a_m[pa].second/2;
                }else{
                    answer += a_m[pa].second/2 + 1;
                }
            }
            break;
        }
        if(a_m[pa].first + a_m[pb].first > limit){
            answer += a_m[pa].second;
            pa++;
        }else{
            if(a_m[pa].second > a_m[pb].second){
                answer += a_m[pb].second;
                a_m[pa].second -= a_m[pb].second;
                pb--;
            }else if(a_m[pa].second < a_m[pb].second){
                answer += a_m[pa].second;
                a_m[pb].second -= a_m[pa].second;
                pa++;
            }else{
                answer += a_m[pa].second;
                pa++;
                pb--;
            }            
        }
    }

        // 기본적으로 a_m[pa or pb].second 가 0이면 다음걸로 패스.
        // a_m[pa].second가 0이면 pa이동
        // a_m[pa].first + a_m[pb].first > limit 면 pb이동
        // a_m[pa].first + a_m[pb].first <= limit 면 둘이 실행
        // 종료 조건 = pa , pb가 a_m 끝에 왔을 때.
    


    return answer;
}

int main(){
    vector<int>people = {40, 55, 55, 60, 60, 60, 70, 80};
    int limit = 100;
    int answer = solution(people,limit);
    cout << answer;


    return 0;
}

/*

        for(int j = i ; j <a_m.size() ; j++){
            
            if(a_m[j].second == 0){
                continue;
            }else{
                if(a_m[i].first + a_m[j].first > limit){
                    continue;
                }else{
                    if(a_m[i].second > a_m[j].second){
                        answer += a_m[j].second;
                        a_m[i].second = a_m[i].second - a_m[j].second;
                        a_m[j].second = 0;
                    }else if(a_m[i].second < a_m[j].second){
                        answer += a_m[i].second;
                        a_m[j].second = a_m[j].second - a_m[i].second;
                        a_m[i].second = 0;
                    }else{
                        answer += a_m[i].second;
                        a_m[i].second = 0;
                        a_m[j].second = 0;
                    }
                }
            }
        }
        if(a_m[i].second!=0){
            if(a_m[i].second %2 == 0){
                answer+=a_m[i].second/2;
                a_m[i].second = 0;
            }else{
                answer+=((a_m[i].second/2) + 1);
                a_m[i].second = 0;
            }
        }

*/