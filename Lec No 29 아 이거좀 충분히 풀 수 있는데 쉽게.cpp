#include<iostream>
using namespace std;

int main(){
	freopen("input.txt","rt",stdin);
	int n;
	int j=0;
	int cnt=1;
	int tmp;
	scanf("%d",&n);
	//char�� �ұ�??
	char arr[5]; 
	for(int i=10;i<=n;i++){
		tmp = i;
		
		while( tmp != 0 ){
			arr[ j ] = tmp % 10 + '0'; // �̰� �߿��ѰŰ� 
			tmp /= 10;
			j++;
		}
		for(int k=0;k<j;k++){
			if(arr[k]=='3'){
			cnt++;	
			}
		}
		j=0;
		arr[5]='0'; //char �迭 �ʱ�ȭ 
		
	}

	cout << cnt;
	/*
	or we could do this
	for(int i=1; i<=n; i++){
	
	tmp = i;
	while(tmp>0){
		digit = tmp%10;
		if(digit==3) cnt++;
		tmp = tmp/10;
	
	
	}
	
	
	}
	
	
	*/
	return 0;
}
