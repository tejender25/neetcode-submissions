class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        queue<pair<int,int>>q;
        int fresh=0, minutes=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }

        while(!q.empty() && fresh>0){
            int sz = q.size();

            for(int t=0; t<sz; t++){
                auto [i,j] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni<0 || nj<0 || ni>=n || nj>=m) continue;
                    if(grid[ni][nj]!=1) continue;
                    grid[ni][nj]=2;
                    fresh--;
                    q.push({ni,nj});
                }
            }
            minutes++;
        }
        return fresh==0 ? minutes : -1;
    }
};
