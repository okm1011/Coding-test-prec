#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int arr[1001];

class Edge{
public:
    int from;
    int to;
    int value;
    Edge(int a,int b,int c){
        from = a;
        to = b;
        value = c;
    }
    bool operator<(Edge&b){
        return value<b.value; // value 기준으로 오름차순 정렬 -> 앞쪽 value보다 뒤쪽벨류 가 크면 앞에 벨류 먼저
    }
};






int find(int x){ // union & find 관련 find 함수
    if(arr[x]==x){
        return x;
    }else{
        return arr[x]=find(arr[x]);
    }
}
void Union(int x, int y){
    x = find(x);
    y = find(y);
    if(x!=y){
        arr[x] = y; // 각각 집합의 root가 다르면 연결 .
    }
}

int main(){

    freopen("input.txt","rt",stdin);
    int n,m;
    cin >> n >>m;
    vector<Edge>min_valus;
    int res = 0;
    for(int i =1;i<=n;i++){
        arr[i] = i;
        //cout << arr[i]<<" ";
    }
    //cout << "\n";

    for(int i = 0 ; i<m;i++){
        int a,b,c;
        cin >> a >> b>>c;
        min_valus.push_back(Edge(a,b,c));
        //cout << min_valus[i].from <<" "<<min_valus[i].to<<" "<<min_valus[i].value<<"\n";
    }
    sort(min_valus.begin(),min_valus.end()); // 위에 operator 정의를 통해 value 기준으로 오름차순 정렬

    for(int i = 0;i<m;i++){
        int fa = min_valus[i].from;
        int fb = min_valus[i].to;

        if(find(fa)!=find(fb)){
            res = res + min_valus[i].value;
            Union(fa,fb);
        }
    }
    cout << res;
    return 0;
}