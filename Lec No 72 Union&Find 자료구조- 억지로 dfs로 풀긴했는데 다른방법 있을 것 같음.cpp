#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>unf(1001,0);

int find(int v){
    if(v == unf[v]){
        return v;
    }else{
        return unf[v] = find(unf[v]); // 이게 경로 축약해주는거 [중간단계 단축] + 재귀함수
    }

}

void Union(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x!=y){
        unf[x]=y;
    }

}
//Union find 결과적으로 서로소 집합 2개가 생기는거 
//-> 새로운 input data가 여러집단중 하나에만 속하게 되는 경우 이경우에 배열사용 트리형태로 구현한다 
//-> 실제로 그렇진않지만 같은 집합이면 어느 요소나 타고 올라가면 같은 루트가 나온다고 생각하면됨 ( 제일 마지막 unf[v]==v 인 애가 root가 되는거임)
//-> 그니까 결국 차례로 연결하고 맨 끝 루트를 통해 어떤 집합인지 확인하는거.

// 처음에는 unf[i] = i 로 초기화 해줌
// 1 2 3 4 5 6 7 8 9 node
// 1 2 3 4 5 6 7 8 9 connection to
//여기서 부터 input 받아서 find랑 union함수 실행
//한번씩 손코딩하면서 왔다갔다 해보는게 중요 .. 마지막에 2개 들어왔을때 find(a) == find(b) ?? 하면 둘이 같은 집합인지 확인할 수 있음 find가 재귀함수로 root까지 갈테니까

int main(){
    freopen("input.txt","rt",stdin);
    int n , m;
    cin >> n >> m;

    for(int i = 1; i<=n;i++){
        unf[i] = i;    
    }
    for(int i = 1; i<=m;i++){
        int a,b;
        cin >> a>>b;
        Union(a,b);
    }
    int a,b;
    cin >> a>>b;
    if(find(a)==find(b)){
        cout<<"YES";
    }else{
        cout<<"No";
    } 
    


    return 0;
}

// 1 2 3 4 5 6 7 8 9
// 1 2 3 4 5 6 7 8

