#include <iostream>
using namespace std;


int main(){
	
	freopen("input.txt","rt",stdin);
	int n;
	int scan_res=0;
	int arr[1000];
	int res=0;
	int first=0;
	int second=0;
	int flag=0;
	int cnt=1;
	
	while(1){
		
	scan_res=scanf("%d",&n);//n = 14
	
	if(scan_res==-1) break;
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	
	for(int j=2;j<n-2;j++){
		first=arr[j];
		second = arr[j-2];
		flag=0;
		
		//arr[2]~arr[n-3]
		for(int k=-2;k<3;k++){
			if(k==0){
				;
			}else if(arr[k+j]>first){
				flag=1;
				break;
			}else if(arr[k+j]>second){
				second = arr[k+j];
				 
			}else{
				;
			}
			
			

		}
		if(first>second && flag==0){
		res=res+(first-second);}
		
		
	
	}
	
	
	cout<<"#"<<cnt<<" "<<res<<" \n";
	arr[1000]={0};
	res=0;
	cnt++;
	
	}
	
	return 0;
}

