#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int all_cnt = 0;
    for(int i = 0 ; i<name.size();i++){
        if(name[i] !='A')all_cnt+=min((name[i]-'A'),('Z'-name[i]+1));
    }
    answer+=all_cnt;
    
    vector<int>steps;
    // 오,왼,오-왼,왼-오
    // 오
    int index = name.size()-1;
    int right_step = name.size()-1;
    while(name[index] == 'A' && index > 0){
        right_step --;
        index--;
    }
    index = 1;
    int left_step = name.size()-1;
    while(name[index] == 'A' && index <= name.size()-1){
        left_step --;
        index++;
    }
    steps.push_back(right_step);
    steps.push_back(left_step);
    
    for(int i = 0 ; i <name.size();i++){
        int start = 0;
        int end = 0;
       //여기서 왼-오 , 오-왼 스타트 엔드가 애매하니까 싹다해봐그냥 어차피 name 20자임
        if(name[i] != 'A'){
            start = i;
            int index = i+1;
            while(1){
                if(name[index] == 'A'){
                    index++;   
                }else{
                    break;
                }
                
            }
            if(index < name.size())end = index;
            steps.push_back(min(start + start + name.size()-end , name.size()-end +name.size()-end + start ));
        }
    }
    sort(steps.begin(),steps.end());

    answer+=steps[0];
    
        // BBBAAABBAAAAAAAAAAAAAAAAAAAAAAABBBAABB
        
        
        
    return answer;
}
