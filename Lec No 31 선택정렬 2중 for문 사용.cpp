#include <iostream>

using namespace std;

int main(){

	
	freopen("input.txt","rt",stdin);
	//��������. >> �ּ� ���� ã�� �ϳ��� �迭�� ��ġ��Ŵ. 
	//2�� for���� ����ϸ��. 
	
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
