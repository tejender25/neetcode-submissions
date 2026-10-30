class Solution {
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
public:

    void dfs(int i, int j, vector<vector<int>>&heights, vector<vector<bool>>&vis){
        vis[i][j] = true;
        for(int k=0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(ni<0 || nj<0 || ni>=n || nj>=m ||vis[ni][nj]) continue;
            if(heights[ni][nj]>=heights[i][j]) dfs(ni,nj,heights,vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>>pacific(n,vector<bool>(m,0));
        vector<vector<bool>>atlantic(n,vector<bool>(m,0));

        // left
        for(int i=0;i<n;i++) dfs(i,0,heights,pacific);
        // top
        for(int j=0;j<m;j++) dfs(0,j,heights,pacific);
        // right
        for(int i=0;i<n;i++) dfs(i,m-1,heights,atlantic);
        // bottom
        for(int j=0;j<m;j++) dfs(n-1,j,heights,atlantic);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;

    }
};
