#include <iostream>
using namespace std;

int main(){
	int n,i,j,div;
	cin >> n ;
	
	int cnt = 0, plus;
for(i=1;i<=n;i++){
	div=10000;
	plus = 5;
        while(div > 0){
            if(i / div != 0){
                cnt += plus;
                div /= 10;
            	plus--;
            }
            div /= 10;
            plus--;
        }
	}

	cout << cnt;
	
	return 0;
}

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
