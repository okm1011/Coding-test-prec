#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string,int>m;
    for(int i =0; i<want.size();i++){
        m.insert({want[i],number[i]});
    }
    
    
    for(int i = 0; i<discount.size()-9;i++){
        
        map<string,int>temp = m;
        for(int j = i ; j<i+10;j++){

            if(temp.find(discount[j])!=temp.end()){
                temp[discount[j]]--;
            }
        }
        bool flag = true;
        for(int k = 0 ; k<want.size();k++){
            if(temp[want[k]] > 0){
                flag = false;
            }
        }
        if(flag)answer++;

    }
    return answer;
}

int main(){
    vector<string>want = {"banana", "apple", "rice", "pork", "pot"};
    vector<int>number = {3, 2, 2, 2, 1};
    vector<string>discount = {"apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana", "chicken", "apple"};
    int answer = solution(want,number,discount);
    cout << answer;
    return 0;
}
