#include <iostream>

using namespace std;

int main(){

	
	freopen("input.txt","rt",stdin);
	//��������. >>�ϳ��� �̾Ƽ� ���ο� �񱳽�Ų ��  �ϳ��� �迭�� ��ġ��Ŵ. 
	//2�� for���� ����ϸ��. 
	
	int n;
	int tmp;
	 
	
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	//idx�� ��� ���� �� �ϳ��� �ϴ°� 
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
