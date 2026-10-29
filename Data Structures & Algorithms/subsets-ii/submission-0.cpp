class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>&curr, vector<int>&nums){
        ans.push_back(curr);

        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i-1]==nums[i]) continue;
            curr.push_back(nums[i]);
            solve(i+1,curr,nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        solve(0,curr,nums);
        return ans;
    }
};
