#include <iostream>
using namespace std;


int main(){
	freopen("input.txt","rt",stdin);
	int n,i,j,d=1,tmp=0,max=-2147000000,max_NO=0;
	char arr[100]; //이렇게 해야 arr 각각이 0으로 initialize됨. 
	int res[10]={};
	scanf("%s",&arr);
	// aray 사용해서 하나씩 넣어서 for문으로 카운트올려야할 것 같은데 음.
	// 100 자리를 어떡하지.. 문자열로 풀어야함. 
	// -48하면 숫자로 바뀜
	
	for(i=0;arr[i]!='\0';i++){
		tmp=arr[i]-48;
		res[tmp]++;
	}
	
	// 여기 까지하고 제일 높은거에 배열 순서를 다시 output으로 내야함. 
	for(j=0;j!=10;j++){
		if(res[j]>max){
			max = res[j];
			max_NO = j;
			
		}
	}
	
	cout << max_NO;

	
	return 0;
}
