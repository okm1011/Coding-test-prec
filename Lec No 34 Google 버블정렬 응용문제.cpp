#include <iostream>

using namespace std;

int main(){
	/*
	int n,i;
	int j=0;
	freopen("input.txt","rt",stdin);
	scanf("%d",&n);
	
	int tmp;
	int arr1[n]={0};//양수 
	int arr2[n]={0};//음수 
	int cnt1=0;
	int cnt2=0;
	
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		if(tmp>0){
			arr1[cnt1]=tmp; 
			cnt1++;
		}else{
			arr2[cnt2]=tmp;
			cnt2++;
		}
	}
	while(arr2[j]!=0){
		cout<<arr2[j];
		j++;
	}
	j=0;
	while(arr1[j]!=0){
		cout<<arr1[j];
		j++;
	}
	*/
	
	// 이렇게 간단하게도가능함  
	// 맨뒤부터 양수로 채우는거 
	int n,i,j,tmp;
	
	freopen("input.txt","rt",stdin);
	
	scanf("%d",&n);
	
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>0 && arr[j+1]<0){
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
	for(i=0;i<n;i++){
		cout<<arr[i];
	}
	return 0;
}
