#include <iostream>

using namespace std;

int main(){
	freopen("input.txt","rt",stdin);
	
	//1�� ���� -> O(C) = 10��.
	int max = -21470000; 
	int n,k;
	scanf("%d",&n);
	scanf("%d",&k);
	int arr[n];
	int sum =0;
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}//���⼭ 10���� 
	
	//�׳� 2�� for�� ������ 10��Ѿ.. 10��*10��
	// �ٸ����??
	/*for(int j=0;j<n;j++){
		for(int m=0;m<k;m++){
			sum = sum+arr[j+m];
		}
		if(max<sum){
			max = sum;
			}
		sum = 0;
	} */
	for(i=0; i<k ;i++){
		sum+=arr[i];
	}
	max = sum;
	for(i=k;i<n;i++){
		sum=sum+(arr[i]-arr[i-k]); // �� ��ĭ�� �ű��Ǵϱ� �̰� ����å�� �Ẹ�鼭 �ؾ���. ������ ��ĭ�� �Ű����°Ŵϱ� 
		if(max<sum){
			max = sum;
			}
	}
	
	cout << max;
	
	return 0;
}
