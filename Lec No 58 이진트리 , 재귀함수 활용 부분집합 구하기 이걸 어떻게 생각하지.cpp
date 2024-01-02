#include<iostream>
#include<vector>
using namespace std;
int n;
int ch[10];

void dfs(int x){
	if(x>n){
		for(int i=1;i<=n;i++){
		
			if(ch[i]==1){
				cout<<i<<" ";
			}
		}cout << "\n";
	}else{
		ch[x]=1;
		dfs(x+1);
		ch[x]=0;
		dfs(x+1);
		
	}
}


int main(){
	
	freopen("input.txt","rt",stdin);
	cin >> n;
	dfs(1);
	return 0;
	
}
