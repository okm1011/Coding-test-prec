#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    vector<int>ch(1001,0);
    // 숫자 세는용도의 vector배열
    for(int i = 0 ; i < array.size();i++){
        ch[array[i]]++;
    }
    int Max = -2147000;
    int Max_i = 0;
    for(int i = 0 ; i<ch.size();i++){
        if(ch[i] > Max){
            Max = ch[i];
            Max_i = i;
        } else if(ch[i] == Max){
            Max_i = -1;
            // 여기서 -1 때려버리면 더큰애 안나오면 -1 유지니까 이렇게 해면 되겠네.
        }
    }

    answer = Max_i;
    // 문제가 최빈값이 여러개일때 -1 리턴해주는애는 어떻게하지..?
    return answer;
}
int main(){
    vector<int>arr = {1,1,2,2};
    int res = solution(arr);
    cout << res;

    return 0;
}