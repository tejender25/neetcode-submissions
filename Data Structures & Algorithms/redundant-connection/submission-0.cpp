class Solution {
    vector<int>parent,rank;
    int findPar(int x){
        if(x==parent[x]) return x;
        return parent[x] = findPar(parent[x]);
    }
    void join(int a,int b){
        int pa = findPar(a);
        int pb = findPar(b);
        if(pa==pb) return;
        if(rank[pa]<rank[pb]) parent[pa]=pb;
        else if(rank[pa]>rank[pb]) parent[pb]=pa;
        else{
            parent[pa]=pb;
            rank[pb]++;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
        vector<int>ans;
        for(auto &e : edges){
            int a = findPar(e[0]);
            int b = findPar(e[1]);
            if(a!=b) join(a,b);
            else return e;
        }
        return {};
    }
};
