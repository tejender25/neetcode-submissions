class Solution {
    vector<vector<int>>ans;
public:
    void solve(int idx, vector<int>& nums, int target, vector<int>&curr){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(idx == nums.size() || target<0) return;

        curr.push_back(nums[idx]);
        solve(idx, nums, target-nums[idx], curr);

        curr.pop_back();
        solve(idx+1,nums,target,curr);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr;
        solve(0,nums,target,curr);
        return ans;
    }
};
