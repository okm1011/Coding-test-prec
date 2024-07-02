#include<iostream>
#include<string>
using namespace std;


int main(){
    string in_str;
    cin >> in_str;
    int cnt = 0,num = 0;
    string cro[] = {"c=" , "c-" , "dz=", "d-" , "lj" , "nj" , "s=" , "z="};
    string temp;

    for(int i = 0 ; i<in_str.size()-1;i++){
        temp += in_str[i+0];
        temp += in_str[i+1];
        bool flag = false;
        for(int j = 0 ; j<8;j++){
            if(temp == cro[j]){
                cnt++;
                num +=2;
                temp = "";
                i +=1;
                flag = true;
            }

        }
        if(flag)continue;
        if(i != in_str.size()-2){
            temp += in_str[i+2];
            for(int j = 0 ; j<8;j++){
                if(temp == cro[j]){
                    cnt++;
                    num +=3;
                    i +=2;
                    temp = "";
                }
            }                
        }
        temp = "";

    }
    cout << cnt + (in_str.size()-num);




}