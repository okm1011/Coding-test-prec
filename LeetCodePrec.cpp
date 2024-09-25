#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<char>arr;

    while(n>0){
        int x = n%3;
        
        if(x == 0){
            arr.push_back('4');
            n = n/3 -1 ;
        }else if(x == 1){
            arr.push_back('1');
            n = n/3;
        }else{
            arr.push_back('2');
            n = n/3;
        }
        
        // 3으로 나눈 몫 x 나머지 y 나머지가 0일때 4 1일때 1 2일때 2
        // x를 또 3으로 나눴을때 나머지가 0일때 4 1일때 1 2일때 2

        
    }
    for(int i = arr.size()-1;i>=0 ; i--){
        answer += arr[i];
    }
    return answer;
}