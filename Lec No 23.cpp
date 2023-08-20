/*
#include <iostream>
using namespace std;

int main(){
    freopen("input.txt","rt",stdin);
    int n,cnt=1;
    int max = -2147000;

    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }
        for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
			cnt = 1;
        }
    	else{
            cnt ++;
            if(cnt > max){
            max = cnt;
        	}
		}
	}

    cout << max;

    return 0;
}
*/
//for short code

#include <iostream>
using namespace std;

int main(){
    freopen("input.txt","rt",stdin);
    int n,cnt=1;
    int pre,now;
    int max = 1;

    scanf("%d",&n);
    scanf("%d",&pre);
    
    for(int i =2; i<=n; i++){
    scanf("%d",&now);
    if(now>=pre){
    	cnt ++;
    	if(max<cnt){
    		max = cnt;
		}
	}
	else{
		cnt = 1;
	}
	pre = now;
	}
    



    

    cout << max;

    return 0;
}






