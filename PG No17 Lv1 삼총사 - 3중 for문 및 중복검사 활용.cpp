#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int size = number.size();
    //3개의 항에 대해서 전부 탐색해야겠네.
    vector<int>ch(size,0);
    // ijk checking용 ch 배열
    vector<vector<int>>ch2;
    // answer 합 checking
    for(int i = 0 ; i<size;i++){
        ch[i]=1;
        for(int j = 0 ; j<size ; j++){
            if(ch[j]==1)continue;
            ch[j] = 1;
            for(int k = 0 ; k<size ; k++){
                if(ch[k]==1)continue;
                ch[k] = 1;
                if((number[i]+number[j]+number[k])==0){
                    vector<int> comp = {i,j,k};
                    sort(comp.begin(),comp.end());
                    bool flag = true;
                    //ch2 랑 comp 비교해서 중복인지 확인. 정렬하는 이유는 비교해야하니까
                    for(int i = 0 ; i<ch2.size();i++){
                        if(ch2[i] == comp){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        ch2.push_back(comp);
                        answer++;
                    }

                }
                ch[k] = 0;
            }
            ch[j]=0;
        }
        ch[i]=0;
    } 
    return answer;
}
int main(){
    vector<int> number = {-3, -2, -1, 0, 1, 2, 3};
    int answer = solution(number);
    cout << answer;
    return 0;
}