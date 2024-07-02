#include <string>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;


/*모든 노드에 대해 4방향으로 쏨.
문제는 각각의 사이클을 어떻게 끝났고[기존 경로랑 겹쳐지는 순간 끝.] 
기존 사이클이랑 경로가 하나라도 겹치면 동일한 사이클이므로 탈출 ? 다른 노드에서 사이클로 들어오는 경우는 없나? 왜없지????????? ,  
1번 예제 처럼 노드가 4개라면 전체 경로는 16개인거임. 그거 중복체크하면 될 것같음. 2개면 6개?
*/ 
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


bool compare(int a , int b){
    return a<b;
}
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    //일단은 3중포문 들어갈거같은데
    // point 는 중복구조를 어떤 방식으로 체크할까?
    //  3차원 배열 bool[500][500][4] x,y좌표 노드의 4방향에서 들어오는거 기준으로 체크 
    // 0  오른쪽에서 , 1 왼쪽에서 , 2 아래에서 ,3 위에서
    bool ch[500][500][4] = {false};

    for(int i = 0 ; i<grid.size();i++){
        for(int j = 0 ; j < grid[i].size();j++){
            int x = j;
            int y = i;
            
            for(int k = 0 ; k<4 ; k++){
                int pre_x = x;
                int pre_y = y;
                x+=dx[k];
                y+=dy[k];
                int cnt = 0;
                while(1){
                    int d_flag = -1;
                    // 여기서 이제 5가지 경우지 
                    // 1 왼쪽으로 나가는경우
                    if(x<0){
                        x = grid[i].size()-1;
                        if(ch[x][y][0] == false){
                            ch[x][y][0] = true;
                            d_flag = 0;
                            cnt++;
                        }else{
                            break;
                        }

                    }
                    // 2 오른쪽으로 나가는 경우
                    else if(x>=grid[i].size()){
                        x = 0;
                        if(ch[x][y][1] == false){
                            ch[x][y][1] = true;
                            d_flag = 1;
                            cnt++;
                        }else{
                            break;
                        }
                    }
                    // 3 위로 
                    else if(y<0){
                        y = grid.size()-1;
                        if(ch[x][y][2] == false){
                            ch[x][y][2] = true;
                            d_flag = 2;
                            cnt++;
                        }else{
                            break;
                        }

                    }
                    // 4 아래로
                    else if(y>=grid.size()){
                        y = 0 ;
                        if(ch[x][y][3] == false){
                            ch[x][y][3] = true;
                            d_flag = 3;
                            cnt++;
                        }else{
                            break;
                        }

                    }
                    // 5 내부에서 도는경우.
                    else{
                        if(pre_x - x== 1){
                            if(ch[x][y][0] == false){
                                ch[x][y][0] = true;
                                d_flag = 0;
                                cnt++;
                            }else{
                                break;
                            }
                        }else if(pre_x - x == -1){
                            if(ch[x][y][1] == false){
                                ch[x][y][1] = true;
                                d_flag = 1;
                                cnt++;
                            }else{
                                break;
                            }
                        }else if(pre_y - y == 1){
                            if(ch[x][y][2] == false){
                                ch[x][y][2] = true;
                                d_flag = 2;
                                cnt++;
                            }else{
                                break;
                            }
                        }else if(pre_y - y == -1){
                            if(ch[x][y][3] == false){
                                ch[x][y][3] = true;
                                d_flag = 3;
                                cnt++;
                            }else{
                                break;
                            }                          
                        }

                    }
                    //다음 움직이는 단계 직진 좌 , 우
                    if(grid[y][x] == 'S'){
                        if(d_flag == 0){
                            pre_x = x ;
                            pre_y = y ;
                            x-=1;
                        }else if(d_flag == 1){
                            pre_x = x ;
                            pre_y = y ;
                            x+=1;                            
                        }else if(d_flag == 2){
                            pre_x = x ;
                            pre_y = y ;
                            y-=1;
                        }else{
                            pre_x = x ;
                            pre_y = y ;
                            y+=1;
                        }
                    }else if(grid[y][x] == 'L'){
                        if(d_flag == 0){
                            pre_x = x ;
                            pre_y = y ;
                            y+=1;
                        }else if(d_flag == 1){
                            pre_x = x ;
                            pre_y = y ;
                            y-=1;                            
                        }else if(d_flag == 2){
                            pre_x = x ;
                            pre_y = y ;
                            x-=1;
                        }else{
                            pre_x = x ;
                            pre_y = y ;
                            x+=1;
                        }
                    }else if(grid[y][x] == 'R'){
                        if(d_flag == 0){
                            pre_x = x ;
                            pre_y = y ;
                            y-=1;
                        }else if(d_flag == 1){
                            pre_x = x ;
                            pre_y = y ;
                            y+=1;                            
                        }else if(d_flag == 2){
                            pre_x = x ;
                            pre_y = y ;
                            x+=1;
                        }else{
                            pre_x = x ;
                            pre_y = y ;
                            x-=1;
                        }
                    }

                


                }
                if(cnt!=0){
                    answer.push_back(cnt);
                }
            }
        }
    }
    sort(answer.begin(),answer.end(),compare);
    return answer;
}

int main(){

    vector<string>grid = {"R","R"};
    vector<int>answer = solution(grid);

    for(int i = 0; i<answer.size() ; i++){
        cout << answer[i] << " ";
    }

    return 0;
}
