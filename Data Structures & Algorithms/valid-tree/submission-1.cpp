class Solution {
public:
    bool hasCycle(int node, int parent,vector<vector<int>>& adj,vector<bool>&vis){
        vis[node] = true;
        for(int nbr: adj[node]){
            if(nbr==parent) continue;
            if(vis[nbr]) return true;
            if(hasCycle(nbr,node,adj,vis)) return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<vector<int>>adj(n);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>vis(n,false);
        if(hasCycle(0,-1,adj,vis)) return false;

        for(bool seen : vis){
            if(!seen) return false;
        }
        return true;
    }
};
