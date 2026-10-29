class Solution {
    vector<vector<int>>ans;
public:
    void solve(int idx, vector<int>& nums, int target, vector<int>&curr){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        
        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;

            curr.push_back(nums[i]);
            solve(i+1,nums,target-nums[i],curr);
            curr.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin() ,nums.end());
        vector<int>curr;
        solve(0,nums,target,curr);
        return ans;
    }
};
