class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a=0,b=nums[0];
        int n=nums.size();
        for(int i=1;i<=n;i++) a^=i;
        for(int i=1;i<n;i++){
            b^=nums[i];
        }
        return a^b;
    }
};
