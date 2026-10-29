class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }

        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int ni = i+dx[k];
                int nj = j+dy[k];
                if(ni<0 || nj<0 || ni>=n || nj>=m) continue;
                if(grid[ni][nj] != INT_MAX) continue;
                grid[ni][nj] = 1+grid[i][j];
                q.push({ni,nj});
            }
        }
        
    }
};
