class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,0));
        int ans=0;
        // for(int i=1;i<n;i++) dp[i][i]=1;

        for(int len=1;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]==s[j] && (len<=2 || dp[i+1][j-1])){
                    dp[i][j]=true;
                    ans++;
                } 
            }
        }
        return ans;
    }
};
