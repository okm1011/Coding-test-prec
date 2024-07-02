#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
        string answer = "";
    // a=97 z=122 A=65 Z = 90
    // 0~9 = 48~57 
    // -_. = 45,46,95
    for(int i = 0 ; i<new_id.size();i++){
        if(new_id[i]>=65 && new_id[i]<=90 ){
            new_id[i] = new_id[i] + 32;
        }
    }
    
    for(int i = 0 ; i<new_id.size();i++){
        if((new_id[i]>=97 && new_id[i]<=122)||(new_id[i] == 45) || (new_id[i] == 46) || (new_id[i] == 95)||(new_id[i] >= 48 && new_id[i] <= 57)){
            
        }else{
            new_id.erase(i,1);
            // 해당 i부터 1개 삭제
            i--;
            //하나 지웠으니까 하나 뒤로가줘야함.
        }
    }    
    bool flag = false;
    for(int i = 0 ; i<new_id.size();i++){
        if(new_id[i] == 46){
            if(flag){
            // 이미 . 이 직전에 나온경우.
            new_id.erase(i,1);
            i--;                
            }
            flag = true;
            
        }else{
            flag = false;
            // flag reset
        }
    }
    for(int i = 0 ; i<new_id.size();i++){
        if(new_id[i] == 46 && i==0){
            new_id.erase(i,1);
            i--;    
        }
        if(new_id[i] == 46 && i==new_id.size()-1){
            new_id.erase(i,1);
            i--;               
        }
    }
    if(new_id.empty()){
        new_id = "a";
    }
    if(new_id.size()>=16){
        new_id.erase(15,(new_id.size()-14));
    }

    if(new_id[new_id.size()-1] == 46){
        new_id.erase(new_id.size()-1,1);
                       
    }
    if(new_id.size()<=2){
        char temp = new_id[new_id.size()-1];
        while(new_id.size() < 3){
            new_id.push_back(temp);
        }
    }    
    answer = new_id;
    return answer;
}

int main(){
    string new_id = {"abcdefghijklmn.p"};
    string answer = solution(new_id);
    
    cout << answer;


    return 0;
}