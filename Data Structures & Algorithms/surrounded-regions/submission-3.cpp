class Solution {
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
public:
    void dfs(int i,int j, vector<vector<char>>& board){
        board[i][j]='#';
        for(int k=0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(ni<0 || nj<0 || ni>=n || nj>=m) continue;
            if(board[ni][nj]=='O') dfs(ni,nj,board);
        }
    }

    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        // Mark boundary-connected 'O' cells as '#'
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') dfs(i,0,board);
            if(board[i][m-1]=='O') dfs(i,m-1,board);
        }

        for(int j=0;j<m;j++){
            if(board[0][j]=='O') dfs(0,j,board);
            if(board[n-1][j]=='O') dfs(n-1,j,board);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='#') board[i][j]='O';
            }
        }
    }
};
