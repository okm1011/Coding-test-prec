#include <iostream>
using namespace std;

/*
1. a�� A�� ��ȣ�� �˾ƺ� >>  A 65 a 97 Z 90 z 122
2. ���ڿ��� char arr[100] ���� �޾Ƽ� while������ int arr[58] �س��� �ϳ��ϳ� ī��Ʈ�� �ø�
3. �׷��� ���� �ش��ϴ� arr�� ī��Ʈ up ���ֽø��. 
4. �ΰ��� int arr�� �����ϸ� yes ����ϸ� ��. 
*/



int main(){

freopen("input.txt","rt",stdin);

char arr1[100];
char arr2[100];
int iarr1[58] = {};
int iarr2[58] = {};
bool flag;

scanf("%s",&arr1);

for(int i =0; arr1[i]!='\0';i++){
	iarr1[arr1[i]-65]++;	
}
scanf("%s",&arr2);

for(int i =0; arr2[i]!='\0';i++){
	iarr2[arr2[i]-65]++;	
}


for(int j=0;j<=57;j++){
	if(iarr1[j]!=iarr2[j]){
		cout << "No";
		flag = false;
		break;
	}
}
if(flag!=false){

cout << "YES";
}

return 0;

}
