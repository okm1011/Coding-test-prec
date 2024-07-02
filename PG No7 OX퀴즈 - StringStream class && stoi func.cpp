
#include <string>
#include <vector>
#include <sstream>

using namespace std;
//3 - 4 = -3"

//stringstream >> 띄어쓰기[공백] 이나 \n 로 각각 끊어서 스트링에 할당할수가 있음... 
//stoi() >> string to int 변환 ... 이거 함수1 std 1 두개로 코드 10분의 1로 줄어듦...
vector<string> solution(vector<string> quiz) {
    vector<string> answer;

    for(int i = 0 ; i<quiz.size();i++){
        string temp = quiz[i];
        stringstream ss;
        string x,y,z,op;
        int res = 0;


        ss.str(temp);
        ss >> x;
        ss >> op;
        ss >> y;
        ss >> z;// = 은 필요가 없다.
        ss >> z;
        
        if(op[0] == '+'){
            res = stoi(x) + stoi(y);
        }else if(op[0] == '-'){
            res = stoi(x) - stoi(y);
        }
        if(stoi(z) == res){
            answer.push_back("O");
        }else{
            answer.push_back("X");
        }
    }
    

    return answer;
}


int main(){
    vector<string> quiz = {"3 - 4 = -3", "5 + 6 = 11"};
    
   
    vector<string> answer = solution(quiz);

}