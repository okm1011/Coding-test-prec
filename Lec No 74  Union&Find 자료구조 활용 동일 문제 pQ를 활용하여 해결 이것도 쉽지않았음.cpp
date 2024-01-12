#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Node{
public:
    int from;
    int to;
    int value;
    Node(int a,int b,int c){
        from = a;
        to = b;
        value = c;
    }
    bool operator<(const Node&b)const{
        return value>b.value; // 최소힙 생성.
    }
};
int ch[101]; // node visit 확인 배열
vector<Node>arr; // input 받을 vector배열




int main(){
    // 바로 전꺼 Lec No 73-2 Union&Find 문제가 간선의 가중치를 기준으로 올림차순 정렬해놓고 필수 간선만 추가하는식이였으면 이번엔 node 중심 && pQ활용
    // 1번 노드 부터 출발 (1,0) << (from , value) 갈수 있는 노드들 pQ최소힙 에 다 넣고 pop() -> 갈수 있는 노드들 pQ에 넣고 반복 [node check 해줘야함. 내일해야겠다..]
    freopen("input.txt","rt",stdin);
    int n, m; // n = node 수 m = 간선 수
    cin >> n >>m;
    // 필요한거 -> value로 정렬되는 최소힙 [to  node , value 만 있으면 될 것 같은데.] , ch배열[노드 수] , from, to, value input받을 vector배열
    // 이건 union&find 필요없을 것 같다.
    // 하지만 양방향 모두 생각해 봐야할 것 같음 대충 이해는 했는데 이거 그냥 Unf로 풀자 이거 너무 복잡해진거같은데
    int res = 0;
    
    for(int i = 0 ; i <m;i++){
        int a , b , c;
        cin >> a >> b >>c;
        arr.push_back(Node(a,b,c));
    }
    priority_queue<Node> pQ; // 최소힙 pQ
    pQ.push(Node(0,1,0));
    
    while(!pQ.empty()){ 
        cout << pQ.top().value<< " " ; // 왜 17이나오지???
        Node temp = pQ.top();
        pQ.pop();
        int v = temp.to;
        int cost = temp.value;
        cout << v << " "<<ch[v] << " ";
        if(ch[v]==0){
            //cout << cost << " " << ch[8] << " ";
            res = res + cost;
            ch[v] = 1;
            for(int i = 0 ; i<arr.size();i++){
                if(arr[i].from == v){
                    pQ.push(Node(arr[i].from,arr[i].to,arr[i].value));
                    
                }else if(arr[i].to == v && ch[arr[i].from] == 0){
                    pQ.push(Node(arr[i].to,arr[i].from,arr[i].value));
                }
            }
        }
    }
    cout << res;


    






    return 0;

}