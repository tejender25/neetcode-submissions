class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,0));
        int maxLen=0;int start=-1;
        // for(int i=1;i<n;i++) dp[i][i]=1;

        for(int len=1;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(s[i]==s[j] && (len<=2 || dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(len>maxLen){
                        maxLen=len;
                        start=i;
                    }
                } 
            }
        }
        return s.substr(start,maxLen);
    }
};
