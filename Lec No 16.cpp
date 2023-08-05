#include <iostream>
using namespace std;

/*
1. a와 A의 번호를 알아봄 >>  A 65 a 97 Z 90 z 122
2. 문자열을 char arr[100] 으로 받아서 while문으로 int arr[58] 해놓고 하나하나 카운트를 올림
3. 그러면 값에 해당하는 arr에 카운트 up 해주시면댐. 
4. 두개의 int arr가 동일하면 yes 출력하면 끝. 
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
