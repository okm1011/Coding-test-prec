#include <iostream>
using namespace std;

int main(){
	freopen("input.txt","rt",stdin);
	
	int n;
	scanf("%d",&n);
	int arr[n];
	arr[0]=0;
	 
	
	
	for(int i=1;i<n;i++){
		arr[i]=i;
	
	}
	int pre,now,res;
	scanf("%d",&pre);
	
	//arr 0 0 arr1 1 arr2 2 arr3 3 
	// 1 4 2 3 7
	for(int j = 2;j<=n;j++){
		scanf("%d",&now);
		if(pre>now){
			res = pre - now;
		}else if(pre<now){
			res = now - pre;
		}else{
			cout << "no";
			return 0;
		}
		
		arr[res]=0;
		
		pre = now;
		
	} 
	for(int i=1;i<n;i++){
		if(arr[i]!=0){
			cout << "no";
			return 0;
		}
	
	}
	cout << "Yes";
	return 0;
}
