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

//�ᱹ 12!�̸� 1~12���� ���μ� �����ؼ� 2�� 5 ī��Ʈ �ϰ� ���� ������ ���ӵ� 0 ������
 

