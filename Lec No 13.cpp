#include <iostream>
using namespace std;


int main(){
	freopen("input.txt","rt",stdin);
	int n,i,j,d=1,tmp=0,max=-2147000000,max_NO=0;
	char arr[100]; //�̷��� �ؾ� arr ������ 0���� initialize��. 
	int res[10]={};
	scanf("%s",&arr);
	// aray ����ؼ� �ϳ��� �־ for������ ī��Ʈ�÷����� �� ������ ��.
	// 100 �ڸ��� �����.. ���ڿ��� Ǯ�����. 
	// -48�ϸ� ���ڷ� �ٲ�
	
	for(i=0;arr[i]!='\0';i++){
		tmp=arr[i]-48;
		res[tmp]++;
	}
	
	// ���� �����ϰ� ���� �����ſ� �迭 ������ �ٽ� output���� ������. 
	for(j=0;j!=10;j++){
		if(res[j]>max){
			max = res[j];
			max_NO = j;
			
		}
	}
	
	cout << max_NO;

	
	return 0;
}
