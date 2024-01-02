#include<iostream>
#include<vector>
using namespace std;
int n;
int arr1[10]={0};
int arr2[10]={0};
int A=0,B=0;
int flag = 0;

void dfs(int x){
	if(flag == 1){
		return;
	}
	A= 0,B=0;
	
	if(x>n){
		for(int i=1;i<=n;i++){
		
			if(arr1[i]==1){
				A=A+arr2[i];
			}else{
				B=B+arr2[i];
			}
		}if(A==B){
			flag=1;
		}
	}else{
		arr1[x]=1;
		dfs(x+1);
		arr1[x]=0;
		dfs(x+1);
		
	}
}


int main(){
	
	freopen("input.txt","rt",stdin);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>arr2[i];
	}
	
	dfs(1);
	if(flag == 1){
		cout<<"yes";
	}else{
		cout<<"no";
	}
	return 0;
	
}
