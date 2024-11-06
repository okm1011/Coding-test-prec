#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i = 0 ; i<numbers.size();i++){
        long long target = numbers[i];
        vector<int>bits1;
        vector<int>temp;
        int zero_pos = -1;
        while(target != 0){
            temp.push_back(target%2);
            if(target%2 == 0 && zero_pos == -1){
                zero_pos = temp.size();
            }
            target/=2;
        }
        if(zero_pos == -1){
            int add = 1;
            int cnt = 1;
            for(int i = 0 ; i<temp.size()-1 ; i++){
                add+=cnt;
                cnt*=2;
            }
            answer.push_back(numbers[i]+add);
        }else{
            if(zero_pos == 1)answer.push_back(numbers[i]+1); 
            else{
                int add = 1;
                int cnt = 1;
                for(int i = 0 ; i<zero_pos-2 ; i++){
                    add+=cnt;
                    cnt*=2;
                }
                answer.push_back(numbers[i]+add);      
            }
      
        }
        //10111
        //11000
        //11011
        //1011
        //1100

    }
    
    return answer;
}
int main(){
    vector<long long> numbers = {11};
    vector<long long> answer = solution(numbers);
    cout << answer[0];

}