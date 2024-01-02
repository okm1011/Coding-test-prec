#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,arr[101],res[101];

void partition(int,int);
void merge(int ,int);

int main(){
	freopen("input.txt","rt",stdin);
	int n;
	cin>>n;
	
	
	for(int i = 0 ;i<n;i++){
		cin >> arr[i];
	}
	partition(0,n-1);
	for(int i = 0 ;i<n;i++){
		cout << arr[i];
	}
	return 0;
}

void partition(int left,int right){
	int mid;
	if(left<right){
	mid = (left+right)/2;
	partition(left,mid);
	partition(mid+1,right);
	merge(left,right);
	}
}
void merge(int left,int right){
	int mid = ((left+right)/2);
	int j = mid+1;
	int i = left;
	int k = left;
	while(i<=mid && j <=right){
		if(arr[i]<arr[j]){
			res[k++] = arr[i++];
		}else{
			res[k++] = arr[j++];
		}
	}
	if(i>mid){
		while(j<=right){
			res[k++] = arr[j++];
		}
	}else{
		while(i<=mid){
			res[k++] = arr[i++];
		}
	}
	for (int a = left; a <= right; a++) {
		arr[a] = res[a];
	}
	

}
