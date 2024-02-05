#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> quiz){
    vector<string> answer;
    // 0 = 48 , 1 = 49 2 = 50,9 = 57  '-' = 45
    // {"3 - 4 = -3", "5 + 6 = 11"};
    // 띄어쓰기를 기준으로 해야겠다. 총 4번이니까

    for(int i = 0 ; i<quiz.size() ; i++){
        
        string temp = quiz[i];
        int x = 0;
        int res = 0;
        int stat = 0; // 0 은 덧셈 1은 뺄셈
        int step = 0;
        int j = 0;
        int m_f = 0; // 0 은 양수 1 은 음수
        
        while(j<temp.size()){
            int t = temp[j];
            if(t == 32){
                step+=1;
                j++;
                continue;
            }
            if(step==0 || step == 2 || step == 4){
                if(t == 45){
                    m_f=1;
                }else{
                    x = x*10 + (t-48);
                }
                
            }else if(step == 1){
                if(m_f==1 && x!=0){
                    res = -1*x;
                    x = 0;
                    m_f = 0;
                }else if(m_f==0 && x!=0){
                    res = x;
                    x= 0;
                }
                if(t == '+'){
                    stat = 0;
                }else if(t == '-'){
                    stat = 1;
                }
            }else if(step == 3){
                if(stat == 0){
                    if(m_f == 1){
                        x = -1*x;
                        m_f = 0;
                    }
                    res = res+x;
                    x = 0;
                }else if(stat == 1){
                    if(m_f == 1){
                        x = -1*x;
                        m_f = 0;
                    }
                    res = res - x ;
                    x = 0;
                }
            }   
            j++;
        }
            
        if(m_f == 1){
            x = -1*x;
        }
        cout << "res : " << res <<" x: "<< x << "\n";
    }
    
    return answer;
}


int main(){
    vector<string> quiz = {"3 - 4 = -3", "5 + 6 = 11"};
    
   
    vector<string> answer = solution(quiz);

}