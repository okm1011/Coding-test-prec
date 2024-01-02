#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void dfs(int,int);
int arr[11] = {0};
int n , m , cnt = 0,path[11];


int main(int argc, char** argv) {
	freopen("input.txt","rt",stdin);
	cin >> n >>m;
	
	for(int i =1;i<=n;i++){
		cin >> arr[i];
		
	}
	dfs(1,0);
	
	if(cnt==0){
		cout<<"-1";
	}else{
		cout<<cnt;
	}
	
	return 0;
}

void dfs(int x,int val){
	
	if(x>n){
		//cout<<"val: "<<val<<" ";
		if (val==m){
			
			cnt++;
			for(int i =1;i<x;i++){
				cout<<path[i];
			}cout<<" ";
		}
		return;
	}
	path[x] = arr[x];
	dfs(x+1,val+arr[x]);
	path[x] = -arr[x];
	dfs(x+1,val-arr[x]);
	path[x] = 0;
	dfs(x+1,val);
	
}

/*
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


*/

