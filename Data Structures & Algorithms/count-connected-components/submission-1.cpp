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

    int countComponents(int n, vector<vector<int>>& edges) {
        rank.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto &e : edges){
            join(e[0],e[1]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) cnt++;
        }
        return cnt;
    }
};
