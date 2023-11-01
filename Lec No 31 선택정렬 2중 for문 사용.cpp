#include <iostream>

using namespace std;

int main(){

	
	freopen("input.txt","rt",stdin);
	//선택정렬. >>하나를 뽑아서 전부와 비교시킨 후  하나씩 배열에 위치시킴. 
	//2중 for문을 사용하면됨. 
	
	int n;
	int tmp;
	 
	
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	//idx를 사용 최종 비교 하나만 하는거 
	int idx;
	
	for(int j=0;j<n;j++){
		idx = j
		for(int k=j+1;k<n;k++){
			if(arr[idx]>arr[k]){
				idx = k
			}
		
		}
		tmp = arr[j];
		arr[j]=arr[idx];
		arr[idx]=tmp;
	}
	
	cout << arr[5];

	return 0;	
}
