class Solution {
public:
    int excludeFirst(vector<int>nums, int s, int e){
        int n = e-s+1;
        if(n==1) return nums[s];

        vector<int>dp(n+1,0);
        dp[1]=nums[s];
        dp[2]=max(nums[s+1],dp[1]);
        for(int i=3;i<=n;i++){
            dp[i]=max(dp[i-1], dp[i-2]+nums[s+i-1]);
        }
        return dp[n];
    }

    int excludeLast(vector<int>nums, int s, int e){
        int n = e-s+1;
        if(n==1) return nums[s];

        vector<int>dp(n+1,0);
        dp[1]=nums[s];
        dp[2]=max(nums[s+1],dp[1]);
        for(int i=3;i<=n;i++){
            dp[i]=max(dp[i-1], dp[i-2]+nums[s+i-1]);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(excludeFirst(nums,1,n-1), excludeLast(nums,0,n-2));
    }
};
