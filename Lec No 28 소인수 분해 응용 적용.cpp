#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	freopen("input.txt","rt",stdin);
	scanf("%d",&n);
	int Two = 0;
	int Five = 0;
	
	for(int i=2;i<=n;i++){
		int tmp = i;
		while(1){
			if(tmp%2==0){
				tmp = tmp/2;
				Two++;
				if(tmp == 1){
					break;
				}
			}else if(tmp%5==0){
				tmp = tmp/5;
				Five++;
				if(tmp == 1){
					break;
				}
			}else{
				break;
			}
		}
	}

	
	if(Two>=Five){
		cout<<Five;
	}else{
		cout<<Two;
	}
		
	return 0;
}

//결국 12!이면 1~12까지 소인수 분해해서 2랑 5 카운트 하고 둘중 작은게 연속된 0 개수임
 

