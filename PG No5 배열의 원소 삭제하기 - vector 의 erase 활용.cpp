#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    for(int i = 0; i<delete_list.size() ; i++){
        int temp = delete_list[i];
        for(int j = 0 ; j < arr.size() ; j++){
            if(arr[j]==temp){
                arr.erase(arr.begin()+j);
            }
        }
    }
    // point 는 vector의 erase 함수 = 매개변수에는 지울것의 주소값을 넣어줘야해서 begin() + i 값으로 했음
    for(int i  = 0; i< arr.size();i++){
        answer.push_back(arr[i]);
    }
    return answer;
}
int main(){
    vector<int>arr = {293,1000,395,678,94};
    vector<int> delete_list = {94,777,104,1000,1,12};
    vector<int> answer = solution(arr,delete_list);
    

    for(int i = 0 ; i<answer.size() ; i++){
        cout << answer[i] << " ";
    }
}