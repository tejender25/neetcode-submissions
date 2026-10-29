class Solution {
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
public:
    int dfs(int i,int j, vector<vector<int>>&grid, vector<vector<bool>>&vis){
        if(vis[i][j]) return 0;
        vis[i][j]=1;
        int islandArea=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1 && !vis[ni][nj]){
                islandArea+=dfs(ni,nj,grid,vis);
            }
        }
        return islandArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int area= dfs(i,j,grid,vis);
                    if(area>maxArea) maxArea = area;
                }
            }
        }
        return maxArea;
    }
};
