#include <iostream>
using namespace std;
int arr[1000000];

int main(){
	
	freopen("input.txt","rt",stdin);
	int t,n; 
	
	scanf("%d",&t);
	
	
	int max;
	int i,j,k;
	int sum=0;
	
	for(i=0;i<t;i++){
		
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
			
		} 
		sum=0;
		max=j-1;
		for(k=j-2;k>=0;--k){
			
			
			if(arr[max]>arr[k]){
				sum+=(arr[max]-arr[k]);
			}else{
				max=k;
			}
		
			
			
		}
		
		cout<<"#"<<i+1<<" "<<sum<<"\n";
	}
	
	
	return 0;
} 
