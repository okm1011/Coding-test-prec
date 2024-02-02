#include <string>
#include <vector>
#include <iostream>
using namespace std;


vector<string> solution(string my_string) {
    string temp;
    vector<string>answer;
    for(int i = 0 ; i<my_string.size();i++){
        if(my_string[i]!=' '){
            temp+=my_string[i];
        }else{
            answer.push_back(temp);
            temp ="";
        }
    
    }
    answer.push_back(temp);
    return answer;
}
