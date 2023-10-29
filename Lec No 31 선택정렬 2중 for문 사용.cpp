#include <iostream>

using namespace std;

int main(){

	
	freopen("input.txt","rt",stdin);
	//선택정렬. >> 최소 값을 찾고 하나씩 배열에 위치시킴. 
	//2중 for문을 사용하면됨. 
	
	int n;
	int tmp;
	
	
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	
	
	for(int j=0;j<n;j++){
		for(int k=j+1;k<n;k++){
			if(arr[j]>arr[k]){
				tmp = arr[j];
				arr[j]=arr[k];
				arr[k]=tmp;
			}
		}
	}
	
	cout << arr[5];

	return 0;	
}
