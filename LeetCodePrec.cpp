class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //이거 아는거임
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        int n = matrix.size();
        int m = matrix[0].size() ;
        vector<vector<int>> ch(n,vector<int>(m,0));
        int cnt_max = n*m;
        int direc = 0;
        int x = 0;
        int y = 0;
        vector<int>answer;
        while(answer.size() < cnt_max){
            answer.push_back(matrix[y][x]);
            ch[y][x] = 1;
            int n_x = x+dx[direc];
            int n_y = y+dy[direc];
            if(n_x < m && 0<=n_x && n_y <n && 0<=n_y && ch[n_y][n_x]==0){
                x = n_x;
                y = n_y;
            }else{
                direc++;
                if(direc>3){
                    direc = 0;
                }
                x = x+dx[direc];
                y = y+dy[direc];
            }
        }
        return answer;
    }
};