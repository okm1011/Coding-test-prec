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
10���� N�ε� 1�ʾȿ� �Ϸ��� �ð����⵵ O(N) �̿����ؼ� �Ʒ����� 
for�� while �Ѵ� ����... ��Ģ�� �� �����غ�����.
1~9 -> +1 �� 9 �� =9
10~99 -> +2 �� 90 �� = 180
100~999 -> +3 �� 900 �� = 2700

���� 1050���� ������ �ϸ� 9+180+2700+(1050-999)*+4 

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
