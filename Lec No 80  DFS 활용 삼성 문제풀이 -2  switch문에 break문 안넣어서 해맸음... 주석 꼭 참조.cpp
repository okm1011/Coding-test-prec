#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>num;
vector<int>opt;
int n;
int Max = -2147000000;
int Min = 2147000000;
int ch[3];

void dfs(int v,int sum){
    
    if(v>n-1){
        if(sum > Max){
            Max = sum;
        }
        if(sum < Min){
            Min = sum;
        }
        return;
    }else{
        for(int i =0 ; i<4;i++){
            
            // switch 문 쓸때 break 안넣어주면 case 만족하는거 이후 끝나는게 아니고 밑에 나머지 case 코드가 전부 실행[여기서는 dfs가 쭉불려져버림,....]'
            // 이것때매 2시간 해맸음.
            
            switch(i){
                
                case 0:
                    
                    
                    if(opt[i]>0){
                        
                        opt[0]--;
                        dfs(v+1,sum+num[v]);
                        opt[0]++;
                    }
                    break;
                case 1:
                    
                    if(opt[i]>0){
                        
                        opt[1]--;
                        dfs(v+1,sum-num[v]);
                        opt[1]++;
                    }
                    break;                 
                case 2:
                    
                    if(opt[i]>0){
                        
                        opt[2]--;
                        dfs(v+1,sum*num[v]);
                        opt[2]++;
                    }
                    break;
                case 3:
                    
                    if(opt[i]>0){
                        
                        opt[3]--;
                        dfs(v+1,sum/num[v]);
                        opt[3]++;
                    }
                    break;
                
            }
        }
    }
}
    


int main(){
    freopen("input.txt","rt",stdin);
    cin >> n;
    for(int i = 0 ; i<n;i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    for(int i = 0 ; i<4;i++){
        int temp;
        cin >> temp;
        opt.push_back(temp);
        
    }
    dfs(1,num[0]); // level = n-1 , for문으로 4개 다 돌리면서 opt -- 하면될거같은데

    cout << Max << Min;
    return 0;
}