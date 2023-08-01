#include <iostream>
using namespace std;

int main(){
	
	freopen("input.txt","rt",stdin);
	int n,cnt=1,d=9,sum=0,res=0;
	
	scanf("%d",&n);
	
	while(n>d+sum){
		res = res+(cnt*d);
		sum = sum + d;
		d=d*10;
		cnt++;
	}
	res=res+((n-sum)*cnt);

	
	cout << res;
	
	
	
	
	return 0;
} 

/*
10억의 N인데 1초안에 하려면 시간복잡도 O(N) 이여야해서 아래같이 
for랑 while 둘다 못씀... 규칙을 잘 생각해봐야함.
1~9 -> +1 씩 9 개 =9
10~99 -> +2 씩 90 개 = 180
100~999 -> +3 씩 900 개 = 2700

만약 1050에서 끝났다 하면 9+180+2700+(1050-999)*+4 

*/

//correct answer below 
/*
int main(){
freopen("input.txt","rt",stdin);
int n, i, cnt=0, tmp;
scanf("%d",&n);
for(i=1;i<=n;i++){
	tmp = i;
	while(tmp>0){
	tmp=tmp/10;
	cnt++;
}
	
}

printf("%d\n",cnt);
return 0;
}
*/
