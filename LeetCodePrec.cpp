#include <string>
#include <vector>
#include <iostream>

using namespace std;
int gcd(int a, int b){
    if(b==0)return a;
    else{
        return gcd(b,a%b);
    }
    
}

int get_gcd_all(vector<int>array,int size){
    if(size == 1)return array[0];
    else{
        int cnt = 2;
        int gcd_temp = gcd(array[0],array[1]);
        while(cnt<size){
            if(gcd_temp == 1)return 1;
            gcd_temp = gcd(max(gcd_temp,array[cnt]),min(gcd_temp,array[cnt]));
            cnt++;
        }
        return gcd_temp;            
    }

    
    
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    // arr a의 최대 공약수로 b 가 다 나누어지는데 a보다 작은 공약수로 안나눠지는건 말이 안되는거같기도함
    int A_gcd = get_gcd_all(arrayA,arrayA.size());
    int B_gcd = get_gcd_all(arrayB,arrayB.size());
    if(A_gcd == 1 && B_gcd == 1 || A_gcd == B_gcd)return 0;
    else{
        bool A_gcd_flag = false;
        bool B_gcd_flag = false;
        
        if(A_gcd != 1){
            A_gcd_flag = true;
            for(int i = 0 ; i<arrayB.size();i++){
                if(arrayB[i]%A_gcd == 0)A_gcd_flag = false;
            }            
        }
        if(B_gcd != 1){
            B_gcd_flag = true;
            for(int i = 0 ; i<arrayA.size();i++){
                if(arrayA[i]%B_gcd == 0)B_gcd_flag = false;
            }            
        }
        if(A_gcd_flag && B_gcd_flag)answer = max(A_gcd, B_gcd);
        else if(A_gcd_flag && !B_gcd_flag) answer = A_gcd;
        else if(!A_gcd_flag && B_gcd_flag) answer = B_gcd;
        else answer = 0;

    }


    return answer;
}