#include <iostream>
using namespace std;
//버블정렬 하나하나씩 비교해서 배열의 끝부터 채워넣음 시간복잡도 좋지않음 

int main(){
	freopen("input.txt","rt",stdin);
	int n,tmp;
	scanf("%d",&n);
	int arr[n]={};
	for(int k=0;k<n;k++){
		scanf("%d",&arr[k]);
	} 
	
	
	//가장큰거부터 배열의끝
	
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(arr[j]>arr[j+1]){
				tmp = arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=tmp;
			}
		}
	} 
	
	/*for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				tmp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	} */
	
	for(int m=0;m<n;m++){
		printf("%d ",arr[m]);
		
	} 
	
	
	
	return 0;
}
