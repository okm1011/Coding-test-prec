#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int num[10];
int res[9];
// x= level
void dfs(int x){
    if(x==9){// 이상태에서 send+ more = money 가능한지 확인. res = sendmory


        int a=0,b=0,c=0;
        a = (1000 * res[1]) + (100 * res[2]) + (10 * res[3]) + res[4];
        b = (1000 * res[5]) + (100 * res[6]) + (10 * res[7]) + res[2];
        c = (10000 * res[5]) + (1000 * res[6]) + (100 * res[3]) + (10 * res[2]) + res[8];
        //cout << " a: " << a << " b: " << b << " c "<< c  <<"\n";
        if(a+b == c){
            for(int i = 1;i<=8;i++){
                cout << res[i] << " ";
            }cout<<"\n";
        }else{
            return;
        }
        /*for(int i = 1;i<=8;i++){
            cout<<res[i]<<" ";
        }cout << "\n";*/
        
    }
    // x 로 level 넘겨주고 번호 중복은 배열 ch 로 확인?
    // 아 여기서 s , m 는 0 안되고 나머지는 0이 가능하네 
    if(x == 1 || x == 5){
        for(int i = 1;i<10;i++){
            if(num[i]==0){
                res[x] = i;
                num[i]=1;
                dfs(x+1);
                num[i]=0;
            }
        }
    }else{
        for(int i = 0;i<10;i++){
            if(num[i]==0){
                res[x] = i;
                num[i]=1;
                dfs(x+1);
                num[i]=0;
            }
        }        
    }

}

int main(){
    //send + more = money
    // sendmory
    // 변수 8개 각각 1~9사이 중복없음. dfs??로???

        dfs(1);
    
    

    


    return 0;
}